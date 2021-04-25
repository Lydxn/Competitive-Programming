#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int magic[] = {1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 18, 19, 20, 22, 23, 24, 26, 27, 29, 30, 31, 33, 34, 36, 37, 39, 41, 42, 44, 45, 47, 48, 50, 52, 53, 55, 57, 58, 60, 62, 63, 65, 67, 68, 70, 72, 74, 75, 77, 79, 81, 82, 84, 86, 88, 90, 91, 93, 95, 97, 99, 101, 102, 104, 106, 108, 110, 112, 114, 116, 117, 119, 121, 123, 125, 127, 129, 131, 133, 135, 137, 139, 141, 143, 145, 147, 149, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 187, 189, 191, 193, 195, 197, 199, 201, 203, 206, 208, 210, 212, 214, 216, 218, 220, 222, 225, 227, 229, 231, 233, 235, 237, 239, 242, 244, 246, 248, 250, 252, 255, 257, 259, 261, 263, 265, 268, 270, 272, 274, 276, 279, 281, 283, 285, 287, 290, 292, 294, 296, 298, 301, 303, 305, 307, 310, 312, 314, 316, 319, 321, 323, 325, 328, 330, 332, 334, 337, 339, 341, 343, 346, 348, 350, 352, 355, 357, 359, 362, 364, 366, 369, 371, 373, 375, 378, 380, 382, 385, 387, 389, 392, 394, 396, 399, 401, 403, 406, 408, 410, 413, 415, 417, 420, 422, 424, 427, 429, 431, 434, 436, 438, 441, 443, 445, 448, 450, 452, 455, 457, 460, 462, 464, 467, 469, 471, 474, 476, 479, 481, 483, 486, 488, 491, 493, 495, 498, 500, 503, 505, 507, 510, 512, 515, 517, 519, 522, 524, 527, 529, 532, 534, 536, 539, 541, 544, 546, 549, 551, 554, 556, 558, 561, 563, 566, 568, 571, 573, 576, 578, 580, 583, 585, 588, 590, 593, 595, 598, 600, 603, 605, 608, 610, 613, 615, 617, 620, 622, 625, 627, 630, 632, 635, 637, 640, 642, 645, 647, 650, 652, 655, 657, 660, 662, 665, 667, 670, 672, 675, 677, 680, 682, 685, 687, 690, 692, 695, 698, 700, 703, 705, 708, 710, 713, 715, 718, 720, 723, 725, 728, 730, 733, 736, 738, 741, 743, 746, 748, 751, 753, 756, 758, 761, 764, 766, 769, 771, 774, 776, 779, 781, 784, 787, 789, 792, 794, 797, 799, 802, 805, 807, 810, 812, 815, 817, 820, 823, 825, 828, 830, 833, 836, 838, 841, 843, 846, 849, 851, 854, 856, 859, 862, 864, 867, 869, 872, 875, 877, 880, 882, 885, 888, 890, 893, 895, 898, 901, 903, 906, 908, 911, 914, 916, 919, 922, 924, 927, 929, 932, 935, 937, 940, 943, 945, 948, 950, 953, 956, 958, 961, 964, 966, 969, 972, 974, 977, 980, 982, 985, 987, 990, 993, 995, 998, 1001, 1003, 1006, 1009, 1011, 1014, 1017, 1019, 1022, 1025, 1027, 1030, 1033, 1035, 1038, 1041, 1043, 1046, 1049, 1051, 1054, 1057, 1059, 1062, 1065, 1067, 1070, 1073, 1075, 1078, 1081, 1083, 1086, 1089, 1092, 1094, 1097, 1100, 1102, 1105, 1108, 1110, 1113, 1116, 1118, 1121, 1124, 1126, 1129, 1132, 1135};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		int x; cin >> x;
		cout << "The length of " << x << "! is " << magic[x] << '\n';
	}
	return 0;
}
