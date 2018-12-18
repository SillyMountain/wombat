#ifndef HAVE_UTILS_TIMER_HPP
#define HAVE_UTILS_TIMER_HPP

#include <chrono>
//TODO: move to .cpp file

class Timer
{
	private:
		typedef std::chrono::high_resolution_clock clock;
		typedef std::chrono::duration<double, std::ratio<1>> second;
		std::chrono::time_point<clock> ref;

	public:
		Timer()
		{
			this->reset();
		}

		void reset()
		{
			ref = clock::now();
		}

		double elapsed() const
		{
			return std::chrono::duration_cast<second>(
				clock::now() - this->ref
			).count();
		}
};

#endif
