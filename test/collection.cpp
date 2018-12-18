#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <wombat/collections/Array.hpp>
#include <wombat/utils/timer.hpp>

#define N 10000

#define DUMP_TIMING(l) {printf("%30s: %.2lf [s]\n", l, t.elapsed()); t.reset();}

Timer t;

void testWombatArray()
{
	Array<int> a;
	for(int x = 0; x < N; x++)
	{
		a.add(x);
	}

	DUMP_TIMING("wombat.array.insert");

	for(int x = 0; x < N; x++)
	{
		assert(a.contains(x));
	}

	DUMP_TIMING("wombat.array.contains");

	for(int x = 0; x < N; x++)
	{
		a.remove(0);
	}

	DUMP_TIMING("wombat.array.remove");

}

void testSTLArray()
{
	std::vector<int> v;

	for(int x = 0; x < N; x++)
	{
		v.push_back(x);
	}

	DUMP_TIMING("STL.array.insert");

	for(int x = 0; x < N; x++)
	{
		assert(std::find(v.begin(), v.end(), x) != v.end());
	}

	DUMP_TIMING("STL.array.contains");

	for(int x = 0; x < N; x++)
	{
		v.erase(v.begin());
		v.swap(v);
	}

	DUMP_TIMING("STL.array.remove");
}

int main()
{
	testWombatArray();
	puts("--------------------------------------------");
	testSTLArray();
}
