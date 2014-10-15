#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef struct state{
	bool valid;
	bool S[7]; //segments
	state(bool s0, bool s1, bool s2,  bool s3, bool s4, bool s5, bool s6){
        valid = true;
		S[0] = s0;
		S[1] = s1;
		S[2] = s2;
		S[3] = s3;
		S[4] = s4;
		S[5] = s5;
		S[6] = s6;
	}

    state(string bits){ //of len 7
        for(int i=0; i< 7; i++){
            S[i] = (bits[i]=='1');
        }
    }
    string to_string(state &working){
		string str = "";
		for(int i=0; i<7; i++){
			if(S[i] && working.S[i]) str.append("1");
			else str.append("0");
		}
		return str;
	}
	void bitwiseor(state w){
		for(int i=0; i<7; i++){
			if(S[i] or w.S[i]) S[i] = 1;
		}
	}
	
	bool is_subset(state w){
		for(int i=0; i<7; i++){
			if(S[i] && !w.S[i]) return false;
		}
		return true;
	}
} state;

vector<state> num_to_state;

void print_state(state s){
    if(s.S[0]) cout << " __ ";
    cout << "\n";
    if(s.S[5]) cout << "|";
    else cout << " ";

    if(s.S[6]) cout << "__";
    else cout << "  ";

    if(s.S[1]) cout << "|";
    else cout << " ";
    cout << "\n";

    if(s.S[4]) cout << "|";
    else cout << " ";
    if(s.S[3]) cout << "__";
    else cout << "  ";
    if(s.S[2]) cout << "|";
    else cout << " ";
    cout << endl;
}

void init_map(){
    /*
	state s0(1, 1, 1, 1, 1, 1, 0);
	state s1(0, 1, 1, 0, 0, 0, 0);
	state s2(1, 1, 0, 1, 1, 0, 1);
	state s3(1, 1, 1, 1, 0, 0, 1);
    state s4(0, 1, 1, 0, 0, 1, 1);
    state s5(1, 0, 1, 1, 0, 1, 1);
    state s6(1, 0, 1, 1, 1, 1, 1);
    state s7(1, 1, 1, 0, 0, 0, 0);
    state s8(1, 1, 1, 1, 1, 1, 1);
    state s9(1, 1, 1, 1, 0, 1, 1);
    */
	state s0("1111110");
	state s1("0110000");
	state s2("1101101");
	state s3("1111001");
    state s4("0110011");
    state s5("1011011");
    state s6("1011111");
    state s7("1110000");
    state s8("1111111");
    state s9("1111011");
    num_to_state.push_back(s0);
    num_to_state.push_back(s1);
    num_to_state.push_back(s2);
    num_to_state.push_back(s3);
    num_to_state.push_back(s4);
    num_to_state.push_back(s5);
    num_to_state.push_back(s6);
    num_to_state.push_back(s7);
    num_to_state.push_back(s8);
    num_to_state.push_back(s9);
    //for(int i=0; i<num_to_state.size(); i++) print_state(num_to_state[i]);
}

vector<int> get_candidates(state given, state &working){ //for given state, find out the candidates which satisfy fall the segment glow
	vector<int> candidates(10, true);
	for(int i=0; i<7; i++){
		if(given.S[i] == 0 && working.S[i] == 1){ // given state, segment is off, but if it's working, 
												  // then eliminate those digits who have this segment on
			for(int d=0; d<10; d++){
				if(num_to_state[d].S[i] == 1) candidates[d] = 0; 
			}
		}
		if(given.S[i] == 0) continue;
		
		//Now, segment is on for current state, eliminate those digits who have this segment off
		for(int d=0; d<10; d++){
			if(num_to_state[d].S[i] == 0) candidates[d] = 0;
		}
	}
	return candidates;
}

void detect_working(state given, state &working){
	for(int i=0; i<7; i++){
		if(given.S[i]) working.S[i] = 1;
	}
}

void validate_candidate(int digit, state working){
	
}

state get_confirmed_state(int digit, int seqsize){
	state confirmed_state("0000000"); //for which segments, we know whether its working or not
	int curr_digit = digit; //the candidate
	for(int con=0; con<seqsize; con++){
		curr_digit = curr_digit+1;
		if(curr_digit > 9) curr_digit -= 10;
		
		state s = num_to_state[curr_digit];
		confirmed_state.bitwiseor(s);
	}
	return confirmed_state;
}

int main(){
    init_map();
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
		//cout << "**********************" << endl;
        int N;
        vector<state> sequence;
        cin >> N;
        for(int i=0; i<N; i++){
            string bits;
            cin >> bits;
            state s(bits);
            sequence.push_back(s);
            //print_state(s);
        }
        vector<vector<int> > possibilities;
        state working_segments("0000000"); //init with nothing working

        for(int i=0; i<N; i++){
			detect_working(sequence[i], working_segments);
		}
		//cout << "working segments" << endl;
		//print_state(working_segments);
		
		
        for(int i=0; i<N; i++){
			//cout << "candidates for " << endl;
			//print_state(sequence[i]);
			//cout << " are " << endl;
			vector<int> candidates = get_candidates(sequence[i], working_segments); //get candidates corresponding to sequence state i
			for(int i=0; i<10; i++){
				//if(candidates[i]) cout << i << " ";
			}
			//cout << endl;
			for(int j=0; j<candidates.size(); j++) {
				//if(candidates[j]) print_state(num_to_state[j]);
			}
			possibilities.push_back(candidates);
		}
		
		vector<int> answer_candidates;
		//for each "starting sequence"  i.e possibilities[0], take each candidate digit and follow the countdown to see if its possible
		for(int d=0; d<10; d++){
			if(possibilities[0][d]){
				int next = (d-1);
				if(next < 0) next = next+10;
				bool found = true; //i.e if following for loop exits succesfully i.e we're getting the sequence
					//and next will contain the final answer candidate
				for(int i=1; i<possibilities.size(); i++){ //look at each possibilities[i] whether next digit is there
					//cout << "next " << next << " " << possibilities[i][next] << endl;
					if(possibilities[i][next]){
						next = (next-1);
						if(next < 0) next = next+10;
					}
					else{//break this search for sequence starting with d
						found = false;
						break;
					}
				}
				if(found){ //if found i.e search success, add 'next' to answer candidates
					answer_candidates.push_back(next);
				}
			}
		}
		
		//Now we have answer candidates. Valid only if size is exactly 1, else throw error
		if(answer_candidates.size() == 0){
			cout << "Case #" << tc << ": ERROR!" << endl;
			continue;
		}
		else{
			//cout << "Case #" << tc << ": size " << answer_candidates.size() << endl;
			vector<int> final_candidates;
			bool error = false;
			for(int i=0; i<answer_candidates.size();i++){
				int digit = answer_candidates[i]; //and each segment with working segments and output the final state
				//cout << "confirmed state " << endl;
				//print_state(confirmed_state);
				
				//cout << "answer digit" << digit << endl;
				state confirmed_state = get_confirmed_state(digit, sequence.size());
				state dstate = num_to_state[digit];
				//print_state(dstate);
				
				if(!dstate.is_subset(confirmed_state)){
					//cout << "Case #" << tc << ": ERROR!" << endl;
					error = true;
					break;
				}
			}
			
			string output;
			
			if(error == true){
				cout << "Case #" << tc << ": ERROR!" << endl;
				continue;
			}
			else{
				//check if all have same output string
				//string str = dstate.to_string(working_segments);
				//cout << "Case #" << tc << ": " << str << endl;
				output = "";
				for(int i=0; i<answer_candidates.size();i++){
					int digit = answer_candidates[i]; //and each segment with working segments and output the final state
					state dstate = num_to_state[digit];
					string tempstr = dstate.to_string(working_segments);
					if(output != "" && output != tempstr){
						error = true;
						break;
					}
					output = tempstr;
				}
			}
			
			if(error == true){
				cout << "Case #" << tc << ": ERROR!" << endl;
				continue;
			}
			else{
				cout << "Case #" << tc << ": " << output << endl;
			}
		}
    }
}
