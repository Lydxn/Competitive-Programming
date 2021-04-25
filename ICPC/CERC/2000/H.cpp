#include <bits/stdc++.h>

using namespace std;

struct statement {
	string subject, verb, object;
	bool positive;
};

vector<statement> statements;
bool contradiction;

string get_object(string object) { return (object.empty() ? "" : " ") + object; }
string conjugate_do(string subject) { return subject == "I" || subject == "you" ? "don't" : "doesn't"; }
string reverse_subject(string subject) { return subject == "I" ? "you" : subject == "you" ? "I" : subject; }
string conjugate(string verb, string subject) { return verb + (subject == "I" || subject == "you" ? "" : "s"); }
string infinitive(string verb, string subject) { return verb.substr(0, verb.size() - (subject != "I" && subject != "you")); }

string get_word(string& sentence) {
	int idx = 0; string ans = "";
	while (idx < int(sentence.size()) && sentence[idx] != ' ') ans += sentence[idx++];
	sentence = idx < int(sentence.size()) ? sentence.substr(idx + 1) : "";
	return ans;
}

string do_question(string& subject, string& verb, string& object) {
	for (int i = 0; i < int(statements.size()); i++) {
		if ((statements[i].subject == "everybody" || statements[i].subject == subject) && statements[i].verb == verb && statements[i].object == object) {
			subject = reverse_subject(subject);
			if (statements[i].positive) return "yes, " + subject + " " + conjugate(verb, subject) + get_object(object) + ".";
			else return "no, " + subject + " " + conjugate_do(subject) + " " + verb + get_object(object) + ".";
		}
	}
	return "maybe.";
}

string who_question(string& verb, string& object) {
	vector<string> matches; string ans = "";
	for (int i = 0; i < int(statements.size()); i++) {
		if (statements[i].verb == verb && statements[i].object == object) {
			if (statements[i].subject == "everybody") {
				if (statements[i].positive) return "everybody " + conjugate(verb, "everybody") + get_object(object) + ".";
				else return "nobody " + conjugate(verb, "nobody") + get_object(object) + ".";
			}
			if (statements[i].positive) matches.push_back(reverse_subject(statements[i].subject));
		}
	}

	if (matches.empty()) return "I don't know.";
	for (int i = 0; i < int(matches.size()); i++) {
		if (i) ans += i == int(matches.size()) - 1 ? " and " : ", ";
		ans += matches[i];
	}
	return ans + " " + (matches.size() > 1 ? verb : conjugate(verb, matches.back())) + get_object(object) + ".";
}

string what_question(string& subject) {
	vector<statement> matches; string ans = "";
	for (int i = 0; i < int(statements.size()); i++) {
		if (statements[i].subject == "everybody" || statements[i].subject == subject) {
			matches.push_back(statements[i]);
		}
	}

	if (matches.empty()) return "I don't know.";
	ans += reverse_subject(subject) + " ";
	for (int i = 0; i < int(matches.size()); i++) {
		if (i) ans += i == int(matches.size()) - 1 ? ", and " : ", ";
		if (matches[i].positive) ans += conjugate(matches[i].verb, subject) + get_object(matches[i].object);
		else ans += conjugate_do(subject) + " " + matches[i].verb + get_object(matches[i].object);
	}
	return ans + ".";
}

void read_statement(string sentence) {
	if (contradiction) return;
	bool positive = true;

	string subject = get_word(sentence), verb = get_word(sentence), object;
	if (verb == "don't" || verb == "doesn't") positive = false, verb = get_word(sentence);
	else verb = infinitive(verb, subject);

	if (subject == "nobody") positive ^= true, subject = "everybody";
	object = sentence;

	for (int i = 0; i < int(statements.size()); i++) {
		if (statements[i].verb == verb && statements[i].object == object) {
			if (statements[i].subject == "everybody" || statements[i].subject == subject) {
				if (positive != statements[i].positive) contradiction = true;
				return;
			}

			if (subject == "everybody") {
				if (positive != statements[i].positive) contradiction = true;
				statements.erase(statements.begin() + i--);
			}
		}
	}
	statements.push_back({subject, verb, object, positive});
}

string answer(string sentence) {
	if (contradiction) return "I am abroad.";
	string interrogative = get_word(sentence), subject, verb, object;

	if (interrogative == "do" || interrogative == "does") {
		subject = get_word(sentence), verb = get_word(sentence), object = sentence;
		return do_question(subject, verb, object);
	} else if (interrogative == "who") {
		verb = infinitive(get_word(sentence), "who"), object = sentence;
		return who_question(verb, object);
	} else {
		get_word(sentence); subject = get_word(sentence);
		return what_question(subject);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; string sentence;
	cin >> T; cin.ignore();

	for (int i = 1; i <= T; i++) {
		statements.clear(); contradiction = false;
		cout << "Dialogue #" << i << ":\n";

		while (true) {
			getline(cin, sentence);
			if (sentence.back() == '.') read_statement(sentence.substr(0, sentence.size() - 1));
			else if (sentence.back() == '?') cout << sentence << '\n' << answer(sentence.substr(0, sentence.size() - 1)) << "\n\n";
			else {
				cout << sentence << "\n\n";
				break;
			}
		}
	}
	return 0;
}
