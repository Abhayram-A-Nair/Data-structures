#ifndef __STACK_H__
#define __STACK_H__

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class stack{
	
	vector<T> list;
	long long int top_index;
	
	public:
		
		stack(){
			top_index=-1;
		}
		
		stack(stack<T> &object){
			vector<T> temporary_object;
			while(!object.empty()){
				temporary_object.push_back(object.top());
				object.pop();
			}
			
			for(int i=temporary_object.size()-1;i>=0;i--){
				object.push(temporary_object[i]);
				this->push(temporary_object[i]);
			}
		}
		
		stack<T> operator=(stack<T> object){
			vector<T> temporary_object;
			while(!object.empty()){
				temporary_object.push_back(object.top());
				object.pop();
			}
			
			for(int i=temporary_object.size()-1;i>=0;i--){
				object.push(temporary_object[i]);
				this->push(temporary_object[i]);
			}
			
			return *(this);
		}
		
		bool operator==(stack<T> object){
			vector<T> temporary_object;
			while(!object.empty()){
				temporary_object.push_back(object.top());
				T data = object.top();
				if(data!=this->top()){
					for(int i=temporary_object.size()-1;i>=0;i--){
						object.push(temporary_object[i]);
						this->push(temporary_object[i]);
					}
					return false;
				}
				this->pop();
				object.pop();
			}
			
			for(int i=temporary_object.size()-1;i>=0;i--){
				object.push(temporary_object[i]);
				this->push(temporary_object[i]);
			}
			
			return true;
		}
		
		bool empty(){
			return top_index==-1;
		}
		
		T top(){
			if(this->empty()){
				cerr<<"Stack is empty!"<<endl;
			}else{
				return list[top_index];
			}
		}
		
		T push(T element){
			top_index++;
			list.push_back(element);
		}
		
		void pop(T element){
			if(this->empty()){
				cerr<<"Stack is empty!"<<endl;
			}else{	
				top_index--;
				list.pop_back();
			}
		}
		
		void clear(){
			while(top_index!=-1){
				top_index--;
				list.pop_back();
			}
		}
};

#endif
