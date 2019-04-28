// NPOLY.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int cache[101][101];
int N;
int MOD = 20090711;

int poly(int cur, int remain);
int npoly();
int solve();

int main()
{
	int T;
	scanf("%d", &T);
	memset(cache, -1, sizeof(cache));
	while(T--) {
		
		scanf("%d", &N);

		printf("%d\n", solve());
	}
}

int solve()
{
	int ans = 0, npolyAns = 0;
	for (int i = 1; i <= N; ++i)
		ans = (ans + poly(i, N - i)) % MOD;
	npolyAns = npoly();
	ans = (((ans - npolyAns) % MOD) + MOD) % MOD;
	return ans;
}
/*���� ��Ī�� ��츦 �����ϱ� ���� �ݸ� �߸� ������ ������̿��� �����.
�� �� �� ������ ������ 2�� �����ϸ鼭 ������ָ� ��.
�ؿ� i==0�� ���� ���� poly �Լ����� ����� �������� �ʱ� ������
���ܷ� ó��������*/
int npoly()
{
	int ret = 0;
	for (int i = N % 2; N - i >= 0; i += 2) {
		if (i == 0) {
			for (int j = 1; j <= N / 2; ++j)
				ret = (ret + poly(j, (N / 2) - j)) % MOD;
			continue;
		}
		ret += poly(i, (N - i) / 2) % MOD;
	}
	
	return ret;
}

int poly(int cur, int remain)
{
	if (remain == 0) return 1;

	int &ret = cache[cur][remain];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = 1; remain - next >= 0; ++next) {
		ret = ret + (poly(next, remain - next)*(cur + next - 1));
		ret %= MOD;
	}
	return ret;
}