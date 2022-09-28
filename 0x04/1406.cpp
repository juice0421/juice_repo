#include <bits/stdc++.h>
using namespace std;

const 	int MX = 600005;
char	dat[MX];
int		pre[MX], nxt[MX];
int 	m, cursor, unused = 1;
char	command, c;

void	ft_erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if(nxt[addr] != -1)
		pre[nxt[addr]] = pre[addr];
}

void	ft_insert(int addr, char c)
{
	dat[unused] = c;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	nxt[addr] = unused;
	pre[nxt[addr]] = unused;
	unused++;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
	string	s;
	cin >> s;
	for(int i = 0; s[i]; i++){
		ft_insert(i, s[i]);
		cursor++;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> command;
		if(command == 'L' && cursor >= 0)
			cursor--;
		else if(command == 'D' && dat[cursor])
			cursor++;
		else if(command == 'B' && cursor >= 1)
			ft_erase(cursor);
		else if(command == 'P'){
			cin >> c;
			ft_insert(cursor, c);
			cursor++;
		}
		else
			continue;
	}
	traverse();
}