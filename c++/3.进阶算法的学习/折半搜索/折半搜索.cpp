#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void solve() {
    int n;
    long long int m;
    std::cin >> n >> m;
    assert(n > 0 && m > 0);
    std::vector<std::pair<long long int, long long int>> value(n);
    for(int i = 0;i < n;++i) {
        std::cin >> value[i].first;
    }
    for(int i = 0;i < n;++i) {
        std::cin >> value[i].second;
    }
    std::sort(value.begin(), value.end(), [&](const std::pair<long long int, long long int> &p1, const std::pair<long long int, long long int>&p2)->bool {
        if (p1.second != p2.second) {
            return p1.second < p2.second;
        } else {
            return p1.first > p2.first;
        }
    });
    // best[i] 前缀长度为 i 的, 最优是多少
    std::vector<std::vector<std::pair<long long int, long long int>>> best_set(n / 2 + 1);
    for(int s = 0;s < (1 << (n / 2));++s) {
        long long int sum_a = 0;  // a 的和
        long long int sum_w = 0;  // 收益之和
        long long int cnt = 0;    // 长度
        for(int i = 0;i < n / 2;++i) {
            if ((s >> i) & 1) {
                sum_a += value[i].first;
                sum_w += cnt * value[i].second;
                ++cnt;
            }
        }
        if (sum_a <= m) {
            best_set[cnt].emplace_back(sum_a, sum_w);
        }
    }
    // 包含去掉的前缀
    for(int i = 0;i <= n / 2;++i) {
        if (!best_set[i].empty()) {
            std::sort(best_set[i].begin(), best_set[i].end(), [&](const std::pair<long long int, long long int> &p1, const std::pair<long long int, long long int> &p2)->bool {
                if (p1.first != p2.first) {
                    return p1.first < p2.first;
                } else {
                    return p1.second > p2.second;
                }
            });
            std::vector<std::pair<long long int, long long int>> t_best;
            for(const auto &[a, b] : best_set[i]) {
                if (t_best.empty() || t_best.back().second < b) {
                    t_best.emplace_back(a, b);
                }
            }
            best_set[i].swap(t_best);//交换全部
        }
    }//很nb的优化，去除掉前面有更优的情况
    // 保留的后缀
    long long int result = 0;
    for(int s = 0;s < (1 << (n - n / 2));++s) {
        long long int sum_a = 0;
        std::vector<long long int> b_list;
        for(int i = n / 2;i < n;++i) {
            if ((s >> (i - n / 2)) & 1) {
                sum_a += value[i].first;
                b_list.emplace_back(value[i].second);//能直接成整体对象，插入
            }
        }
        if (sum_a > m) {
            continue;
        }
        // 什么都不选
        long long int sum_w = 0;
        long long int cnt = 0;
        for(auto b : b_list) {
            sum_w += cnt * b;
            ++cnt;
        }
        result = std::max(result, sum_w);
        for(int len = 1;len <= n / 2;++len) {
            if (!best_set[len].empty() && best_set[len].front().first <= m - sum_a) {
                int l = 0;
                int r = static_cast<int>(best_set[len].size()) - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (best_set[len][mid].first <= m - sum_a) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                sum_w = best_set[len][r].second;
                cnt = len;
                for(auto b : b_list) {
                    sum_w += cnt * b;
                    ++cnt;
                }
                result = std::max(result, sum_w);
            }
        }
    }
    std::cout << result << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}
