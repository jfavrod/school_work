#define MAX_NAME 25
#define MAX_ACCT_NO 9
#define MAX_BAL 16
#define MAX_ENTRY 80

struct account
{
    char name[MAX_NAME];
    int account_no;
    float balance;
};
