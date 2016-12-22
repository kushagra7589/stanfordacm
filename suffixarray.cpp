#define MAXXN 65536
#define MAXLG 17
char A[MAXN];
struct entry
{
	    int nr[2];
		int p;
} L[MAXN];
int P[MAXLG][MAXN];
int N,i;
int stp, cnt;
int cmp(struct entry a, struct entry b)
{
	    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main()
{
	gets(A);
	for(N=strlen(A), i = 0; i < N; i++)
		 P[0][i] = A[i] - 'a';
	for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
	{ 
		for(i=0; i < N; i++)	
		{									     
			L[i].nr[0]=P[stp- 1][i];
			L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
			L[i].p= i;			
		}	
	sort(L, L+N, cmp);
	for(i=0; i < N; i++)
		P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
	return 0;
}
/*
   LCP Pseudocode :-

   FindLCP (x, y)
       answer = 0

	       for k = ceil(log N) to 0
		       if SortIndex[k][x] = SortIndex[k][y]
		          // sort-index is same if the first k characters are same
				  answer += 2k
			     // now we wish to find the characters that are same in the remaining strings
				 x += 2k
		         y += 2k
*/
