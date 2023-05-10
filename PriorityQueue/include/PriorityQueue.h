#pragma once
#include <list>
#include <stdexcept>

using empty_queue_except = std::out_of_range;

template <typename T>
using priorityQueue = std::list<T>;

template <typename T>
struct MyComperator {
	T operator()(T a, T b) {
		return a - b;
	}
};

template <typename T>
class PriorityQueue {

	MyComperator<T> m_comp;
	priorityQueue<T> m_priorityQueue;

public:

	void push(const T& t) {
		auto it = m_priorityQueue.begin();
		for (; it != m_priorityQueue.end() && m_comp(*it, t) < 0; ++it);
		m_priorityQueue.insert(it, t);
	};

	T poll() {
		if (m_priorityQueue.empty()) {
			throw empty_queue_except("PriorityQueue empty !");
		}
		else {
			T r = m_priorityQueue.front();
			m_priorityQueue.pop_front();
			return r;
		}
	};


};
