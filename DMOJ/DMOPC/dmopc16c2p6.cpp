#include <bits/stdc++.h>

using namespace std;

struct folder {
	string name;
	folder* par;
	map<string, folder*> folders;
	folder(string name, folder* par) : name(name), par(par) {}
};

vector<string> lst, parse;
folder* root = new folder("~", nullptr);
folder* cur = root;

template <typename Container>
void split(const string& str, Container& cont, char delim = ' ') {
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) cont.push_back(token);
}

void recur(folder* f) {
	lst.push_back(f->name);
	for (auto i : f->folders) recur(i.second);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, depth, pdepth = -1; string name, cmd;
	cin >> N;

	while (N--) {
		cin >> depth >> name;
		while (pdepth-- >= depth) cur = cur->par;
		cur->folders[name] = new folder(name, cur);
		cur = cur->folders[name], pdepth = depth;
	}
	cur = root;

    cin.ignore();
	while (true) {
		getline(cin, cmd); parse.clear(); split(cmd, parse);
		switch (parse[0][0]) {
			case 'l': {
				int ptr = 1, sz = parse.size(); lst.clear();
				if (ptr < sz && parse[ptr] == "-r") ++ptr, recur(cur), lst.erase(lst.begin());
				else for (auto i : cur->folders) lst.push_back(i.first);
				sort(lst.begin(), lst.end());

				bool empty = true;
				if (++ptr < sz) {
					regex re(parse[ptr + 1]);
					for (auto i : lst) if (regex_search(i, re)) cout << i << '\n', empty = false;
				} else for (auto i : lst) cout << i << '\n', empty = false;
				cout << (empty ? "\n\n" : "\n");
				break;
			}
			case 'c': {
				string path = parse[1]; lst.clear();
				if (int(path.size()) > 1 && path[0] == '~' && path[1] == '/') cur = root, path = path.substr(2);
				split(path, lst, '/');
				for (auto i : lst) cur = cur->folders[i];
				break;
			}
			case 'm': case 't': {
			    cur->folders[parse[1]] = new folder(parse[1], cur);
			    break;
			}
			case 'p': {
			    string path = "";
			    for (auto i = cur; i; i = i->par) path = i->name + "/" + path;
			    cout << path << "\n\n";
			    break;
			}
			case 'e':
				return 0;
		}
	}
}
