enum states {
	xxx,
	xxx_W,
	yyy
} state;
int stepAcounter;

void main(){
	stepAcounter = 0;

	// Outer state of the system is decomposed in parallel components
	while(1){ 
		taskB();
		taskA();
		taskB();
	}
}

void taskA(){
	//Do something depending on the state of A.
	switch(state){
		case xxx: //Action xxx should be performed.
			//check abort of A.
			if(!abortA){
				switch(stepAcounter){
					case 0:
						subTaskA();
						stepcounter++;
						return;
					case 1:
						//...
						stepcounter++;
						return;
					//..
					case 3:
							//...
							state=xxx_W;
							break;
				}
			} else {
				return;	
			}
// NO break here since taskA goes directly to state xxx_W after finishing action xxx.
		case yyy: //...

		case xxx_W: //transition checking state.
			//check abort of A.
			if(!abortA){
				if(checkTrasitionConditions()){
					state=yyy;	
				}
				// ... 
			} else {
				return;	
			}
			break;
		default:
			return;
	}
}

void subTaskA(){
	while(!endCondition){ 
		taskC();
		taskD();
	}
	//Leave parallel decomposition.
	return;
}
