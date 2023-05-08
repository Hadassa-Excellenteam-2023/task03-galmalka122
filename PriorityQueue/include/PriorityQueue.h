#pragma once
#include <algorithm>
#include <iterator>
#include <list>
#include <exception>

using std::list;


template <typename T>
struct MyComperator {
	T operator()(T a, T b) {
		return a - b;
	}

}


template <typename T>
class PriorityQueue {
   
public:

	void push(const T& t) {
		auto it = m_list.begin();
		for (; it != m_list.end() && m_comp(*it, t) < 0; ++it);
		m_list.insert(it, t);
	};

	T poll() {
		if (m_list.empty()) {
			throw std::exception("PriorityQueue empty !");
		}
		else {
			T r = m_list.front();
			m_list.pop_front();
			return r;
		}
	};

private:
	 m_comp;
	list<T> m_list;
};

