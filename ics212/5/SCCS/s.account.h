h36849
s 00001/00000/00010
d D 1.4 14/10/03 10:04:52 favrod 4 3
c It looks like we have a first draft.
e
s 00000/00000/00010
d D 1.3 14/10/02 07:57:38 favrod 3 2
c 
e
s 00003/00001/00007
d D 1.2 14/10/01 22:54:51 jason 2 1
e
s 00008/00000/00000
d D 1.1 14/10/01 17:07:19 favrod 1 0
c date and time created 14/10/01 17:07:19 by favrod
e
u
U
f e 0
t
T
I 1
#define MAX_NAME 25
I 2
#define MAX_ACCT_NO 9
#define MAX_BAL 16
I 4
#define MAX_ENTRY 80
E 4
E 2

struct account
{
    char name[MAX_NAME];
D 2
    int accountno;
E 2
I 2
    int account_no;
E 2
    float balance;
};
E 1
