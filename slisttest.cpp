#include"slist.hpp"

int main() {
	my_list st;
	for (int i = 5; i > 0; i--) {
		st.push_front(i);
		st.print();
	}
	for (int i = 1; i <= 10; i+=2) {
		st.insert(i, rand());
		st.print();
	}
	st.insert(555, 12132312);
	while (1) {
		if (st.empty()) {
			std::cout << "list has alreadt empty";
			break;
		}
		st.erase(0);
		st.print();
	}
}