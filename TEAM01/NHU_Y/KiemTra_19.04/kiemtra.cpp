#include<stdio.h>
#include<string.h>
#include<math.h>
#include "../../../_src/Log.h"

int KTSoNguyenTo (int x){
	if(x <= 1) return 0 ;
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i == 0)
		return 0;
	}
	return 1;	
} 

int main(){
    LOG_ET("Bai: Loc so nguyen to trong xau\n");
    LOG_WT("Ten: Tran Nhu Y\n");
    LOG_IT("Msv: 21T1020105\n");
    LOG_DT("-----\n");
	char s[500];
	int i = 0;
	int ans = 0;
    printf("Nhap chuoi: ");
	fgets(s, sizeof(s), stdin);
	int len = strlen(s);
    LOG_ET("So nguyen to: ");
	
}
