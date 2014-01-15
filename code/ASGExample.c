enum states {
	 xxx,
	 xxx_W,
	 yyy
};

void main(){
	while(1){
		taskB();
		taskA();
		taskB();
	}
}

void taskA(){
	int stepcounter;
	//...
	switch(state){
		case xxx: //Action xxx should be performed.
			stepcounter = 0;
			switch(stepcounter){
				case 0:
					...
					stepcounter++;
				case 1:
					...
					stepcounter++;

				...
			}
			state=xxx_W;
		// NO break since taskA goes directly to state xxx_W after finishing action xxx.
		case xxx_W:
			checkTrasitionConditions();	
	}
}
