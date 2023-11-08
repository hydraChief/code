
    while(true){
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(temp_burst[i] != 0){
				flag = false;
				break;
			}
		}
		if(flag)
			break;

		for(int i = 0; (i < n) && (queue[i] != 0); i++){
			int ctr = 0;
			while((ctr < tq) && (temp_burst[queue[0]-1] > 0)){
				temp_burst[queue[0]-1] -= 1;
				timer += 1;
				ctr++;

			
				checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
			}
		


			if((temp_burst[queue[0]-1] == 0) && (complete[queue[0]-1] == false)){
			
				turn[queue[0]-1] = timer;	 
				complete[queue[0]-1] = true;
			}
			
			bool idle = true;
			if(queue[n-1] == 0){
				for(int i = 0; i < n && queue[i] != 0; i++){
					if(complete[queue[i]-1] == 0){
						idle = false;
					}
				}
			}
			else
				idle = false;

			if(idle){
				timer++;
				checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
			}

			queueMaintainence(queue,n);
		}
	}
