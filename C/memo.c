if(slimes[pa][2]>slimes[pb][2]){
            slimes[pb][0]=pa;
            slimes[pa][1]+=slimes[pb][1];
        }
        else{
            slimes[pa][0]=pb;
            slimes[pb][1]+=slimes[pa][1];
            if(slimes[pa][2]==slimes[pb][2]){
                slimes[pb][2]++;
            }
        }