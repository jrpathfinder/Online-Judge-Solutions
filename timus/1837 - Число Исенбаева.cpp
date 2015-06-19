#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

#define UNDEFINED 10000

struct Man {
	Man(int number, std::string name) {
		this->number = number;
		this->name = name;
	}

	bool operator<(const Man& man) {
		return this->name < man.name;
	}

	void add(Man* teammate) {
		if(teammate != nullptr)
			teammates.push_back(teammate);
	}

	int number;
	std::string name;
	std::vector<Man*> teammates;
};

bool way2sort(Man* man1, Man* man2) {
	return man1->name < man2->name;
}

std::vector<Man*> Mans;
std::map<Man*, bool> visited;
std::queue<Man*> queue;

int main() {
	int n;
	std::string name[3];

#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> name[0] >> name[1] >> name[2];

		int el[3] = {0};

		for(int l = 0, j = 0; l < 3; l++) {
			for(j = 0; j < Mans.size(); j++) {
				if(Mans[j]->name == name[l]) {
					el[l] = j;
					break;
				}
			}

			if(j == Mans.size()) {
				Mans.push_back(new Man(UNDEFINED, name[l]));
				el[l] = j;
			}
		}

		Mans[el[0]]->add(Mans[el[1]]);	Mans[el[0]]->add(Mans[el[2]]);
		Mans[el[1]]->add(Mans[el[0]]);	Mans[el[1]]->add(Mans[el[2]]);
		Mans[el[2]]->add(Mans[el[0]]);	Mans[el[2]]->add(Mans[el[1]]);
	}

	int index = -1;
	for(int i = 0; i < Mans.size(); i++) {
		if(Mans[i]->name == "Isenbaev") {
			Mans[i]->number = 0;
			index = i;
			break;
		}
	}

	if(index != -1) {
		for(int i = 0; i < Mans.size(); i++) 
			visited[Mans[i]] = false;

		queue.push(Mans[index]);
		visited[Mans[index]] = true;

		while ( !queue.empty() ) {
			Man* node = queue.front();
			queue.pop();

			visited[node] = true;

			for(int i = 0; i < node->teammates.size(); i++) {
				Man* child = node->teammates[i];
				if(!visited[child]) {
					child->number = node->number + 1;
					visited[child] = true;
					queue.push(child);
				}
			}
		}

	}

	std::sort(Mans.begin(), Mans.end(), way2sort);

	for(int i = 0; i < Mans.size(); i++) {
		if(Mans[i]->number != UNDEFINED)
			std::cout << Mans[i]->name << " " << Mans[i]->number << std::endl;
		else
			std::cout << Mans[i]->name << " " << "undefined" << std::endl;
	}

	return 0;
}