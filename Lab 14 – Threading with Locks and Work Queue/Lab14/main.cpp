#include <iostream>
#include <thread>
#include <algorithm>
#include "SharedQueue.h"
#include "Timer.h"

struct Range {
	uint64_t from, to;
};

bool IsPerfectNumber(uint64_t number)
{
	uint64_t limit = number/2;
	uint64_t sum = 0;
	for (uint64_t x = 1; x <= limit; x++)
	{
		if (0 == number%x)
			sum += x;
	}
	return (sum == number);
}

void ThreadWorker(SharedQueue<Range> *workQueue, SharedQueue<uint64_t> *resultQueue)
{
	Range r;
	while (true)
	{
		// read work from queue
		while (workQueue->Remove(r) == false)
		{ std::this_thread::yield(); }
		
		// if from==to, then this is a quit message; we are done
		if (r.from == r.to)
		{
			break;
		}

    // compute whether each number in Range is a perfect number
    // and put perfect numbers into the result queue
		for (uint64_t x = r.from; x < r.to; x++)
		{
			if (IsPerfectNumber(x))
				resultQueue->Add(x);
		}
		
	}
}

void FindPerfectNumbers(uint64_t maxValue, int workSize, unsigned numThreads)
{
	SharedQueue<Range> workQueue;
	SharedQueue<uint64_t> resultQueue;
	Timer t;
	t.StartTimer();
	
	std::thread **threads;
	threads = new std::thread*[numThreads];
	
	
	for (uint64_t x = 1; x < maxValue; x+=workSize)
	{
		workQueue.Add({x, std::min(x+workSize, maxValue)});
	}
	
	for (int x = 0; x < numThreads; x++)
	{
		threads[x] = new std::thread(ThreadWorker, &workQueue, &resultQueue);
	}

	for (int x = 0; x < numThreads; x++)
	{
		workQueue.Add({0,0});
	}
	
	for (int x = 0; x < numThreads; x++)
	{
		threads[x]->join();
		delete threads[x];
	}
	delete [] threads;
	
	std::cout << "Perfect numbers:" << std::endl;
	while (!resultQueue.IsEmpty())
	{
		uint64_t result;
		if (resultQueue.Remove(result))
			std::cout << result << std::endl;
	}
	std::cout << "Finding perfect numbers from 1 to " << maxValue << " took " << t.EndTimer() << " seconds.\n";
	std::cout << numThreads << " threads; work unit " << workSize << " items." << std::endl;
}

int main(int argc, const char * argv[])
{
	unsigned num_threads = std::thread::hardware_concurrency();
	
	FindPerfectNumbers(10000, 10000, 1);
	
	FindPerfectNumbers(10000, 1, 1);
	
	FindPerfectNumbers(10000, 1, num_threads);
	
	FindPerfectNumbers(10000, 100, num_threads);
	
	
	
	
	//FindPerfectNumbers(1000000, 100, num_threads);
	//Shows that more threads are superior as the size increases
	//FindPerfectNumbers(100000, 100, 1);
	//These calls illistrate that 
	//FindPerfectNumbers(1000000, 50, num_threads);
	//FindPerfectNumbers(1000000, 200, num_threads);
	
	
	// This will take a long time for most machines, but try it out to see yourself!
	 //FindPerfectNumbers(1000000, 100, num_threads);
	// This will find the next perfect number, but will take too long in practice
	// FindPerfectNumbers(34000000, 1000, num_threads);
	
	return 0;
}
/*
std::ostream& operator<<(std::ostream& os, const Range& dt)
{
	os << dt.to << '/' << dt.from << '/';
	return os;
}
*/
/**
 * Report here:
 *Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 10000 took 0.193911 seconds.
1 threads; work unit 10000 items.
Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 10000 took 0.196292 seconds.
1 threads; work unit 1 items.
Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 10000 took 0.0469318 seconds.
8 threads; work unit 1 items.
Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 10000 took 0.0431902 seconds.
8 threads; work unit 100 items.
Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 100000 took 3.94372 seconds.
8 threads; work unit 100 items.

//I added this test to better see the scaling
Finding perfect numbers from 1 to 100000 took 18.4133 seconds.
1 threads; work unit 100 items.
Perfect numbers:
6
28
496
8128
//As we can see here work size doesn't really matter 
Finding perfect numbers from 1 to 1000000 took 419.731 seconds.
8 threads; work unit 100 items.
Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 1000000 took 424 seconds.
8 threads; work unit 50 items.
Perfect numbers:
6
28
496
8128
Finding perfect numbers from 1 to 1000000 took 426.476 seconds.
8 threads; work unit 200 items.
 * What are the runtimes for each of the 5 calls above?
 * Can you explain the differences in runtime for computing
 * perfect numbers within the first 10,000 elements?
 *
 *Run times for five calls
 *0.193911
 *0.196292
 *0.0469318
 *0.0431902
 *3.94372
 *
 The first call is just one thread doing all the work, so it never has to context switch with anyone else, the base line.
 The second call is threads doing small ammounts of work, so all the overhead of making threads adds some time to the running of the code
 The next one is 8 threads that all try to do a small amount of work. They must so effectively block each other that it actually runs for a longer time, as well as extra time required to make the threads.
 The next one is also 8 threads taking a larger range, but it must be the overhead of making and running the threads makes it take longer than the one thread. The larger work ammount though does allow for a little less blocking, so it is indeed faster than when each thread does 1 unit of work.

 However, from that extra test we can see as the numbers get better the scaling of the threads is far superior. The tiny ammount is dealing with too small of numbers, so it can't actually be seen that threads are helpful. 
 */
