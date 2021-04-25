#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;

__gnu_cxx::rope<char> comm[1000000]; int idx = 0;

void Init() {}

void TypeLetter(char L) {
    ++idx; comm[idx] = comm[idx - 1];
    comm[idx].push_back(L);
}

void UndoCommands(int U) {
    ++idx; comm[idx] = comm[idx - U - 1];
}

char GetLetter(int P) {
    return comm[idx][P];
}

int main() {
    Init();
    TypeLetter('a');
    TypeLetter('b');
    cout << GetLetter(1) << '\n';
    cout << "HI\n";
}
