if (a<b){
            if(a-i>0&&(b+i)>=(a-i)){
                if((b+i)%(a-i)==0) max_check(a-i);
            }
            if((b-i)>=(a+i)){
                if((b-i)%(a+i)==0) max_check(a+i);
            }
        }
        else{
            if(b-i>0&&(a+i)>=(b-i)){
                if((a+i)%(b-i)==0) max_check(b-i);
            }
            if((a-i)>=(b+i)){
                if((a-i)%(b+i)==0) max_check(b+i);
            }
        }