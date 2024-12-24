#include <bits/stdc++.h>

int sm(int ij, int vd, int ou) {
 int vc = 0;
 if (ij > vd) std::swap(ij, vd); 
 if (vd > ou) std::swap(vd, ou); 
 if (ij > vd) std::swap(ij, vd); 
 if (vc == ij) vc++;
 if (vc == vd) vc++;
 if (vc == ou) vc++;
 return vc;
}

void ot() {
 int ss, de, le;
 std::cin >> ss >> de >> le;

 auto xt = [&](int aj) -> int {
 return (aj + ss - 1) % ss + 1;
 };

 std::vector<int> vc(ss + 1, -1);
 for (int ho = 1; ho <= ss; ho++) {
 int ou = -1;
 if (ho == de) ou = vc[le];
 else if (ho == le) ou = vc[de];
 vc[ho] = sm(vc[xt(ho - 1)], vc[xt(ho + 1)], ou);
 std::cout << vc[ho] << ' ';
 }
 std::cout << '\n';
}

int main() {
 std::cin.tie(nullptr)->sync_with_stdio(false);
 int rb; std::cin >> rb; while (rb--) ot();
 return 0;
}