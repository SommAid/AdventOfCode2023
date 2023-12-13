#include "Day6.h"

// PART 1
int Day6::TotalAmountOfTimeBeatRecord(std::vector<int> times, std::vector<int> distances) {
	int time, dist, myDist, len = times.size();
	std::vector<int> numGreaterDist(len, 0);

	for (int i = 0; i < len; i++) {
		time = times[i];
		dist = distances[i];
		for (int start = 1; start < time; start++) {
			// start is both our start time and velocity if start = 2 ms then vel = 2 mil/s
			myDist = (time - start) * start;
			if (myDist > dist) {
				numGreaterDist[i]++;

			}
		}

	}

	return std::accumulate(numGreaterDist.begin(), numGreaterDist.end(), 1, std::multiplies<int>());
	
}

long long Day6::TotalAmountOfTimeBeatRecord(long long time, long long distance) {

	long long count = 0;

	unsigned long long myDist;
	for (int start = 1; start < time; start++) {
		// start is both our start time and velocity if start = 2 ms then vel = 2 mil/s
		myDist = (time - start) * start;
		if (myDist > distance) {
			//std::cout << "myDist = " << myDist << "\n";
			//std::cout << "start = " << start << "\n";
			//count = time + 1 - start * 2;
			//break;
			count++;
		}
	}
	return count;
}