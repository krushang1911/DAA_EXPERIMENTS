#include <bits/stdc++.h>
using namespace std;

string addStrings(const string &a, const string &b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string subStrings(const string &a, const string &b) { // assume a >= b
    string res;
    int i = a.size() - 1, j = b.size() - 1, borrow = 0;
    while (i >= 0) {
        int diff = (a[i] - '0') - borrow - (j >= 0 ? b[j] - '0' : 0);
        if (diff < 0) diff += 10, borrow = 1;
        else borrow = 0;
        res.push_back(char('0' + diff));
        i--; j--;
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

string karatsuba(const string &x, const string &y) {
    string a = x, b = y;
    // remove leading zeros
    while (a.size() > 1 && a[0] == '0') a.erase(a.begin());
    while (b.size() > 1 && b[0] == '0') b.erase(b.begin());
    if (a.size() == 1 && b.size() == 1) {
        int val = (a[0]-'0') * (b[0]-'0');
        return to_string(val);
    }

    int n = max(a.size(), b.size());
    if (n % 2) n++;
    while ((int)a.size() < n) a = "0" + a;
    while ((int)b.size() < n) b = "0" + b;

    int m = n / 2;
    string a0 = a.substr(0, n - m);
    string a1 = a.substr(n - m);
    string b0 = b.substr(0, n - m);
    string b1 = b.substr(n - m);

    string z0 = karatsuba(a1, b1);
    string z2 = karatsuba(a0, b0);
    string z1 = karatsuba(addStrings(a0, a1), addStrings(b0, b1));
    z1 = subStrings(subStrings(z1, z2), z0);

    // z2 * 10^(2*m) + z1 * 10^m + z0
    z2.append(2 * m, '0');
    z1.append(m, '0');
    string res = addStrings(addStrings(z2, z1), z0);
    // remove leading zeros
    while (res.size() > 1 && res[0] == '0') res.erase(res.begin());
    return res;
}

int main() {
    string x = "12345678";
    string y = "87654321";
    cout << "Product: " << karatsuba(x, y) << endl;
    return 0;
}
