#ifndef SET_HPP
#define SET_HPP

template <typename TData> class Set;
template <typename TData> class LendSet;

#include "nodes.hpp"

template <typename TData> class Set {
	protected:
		SNodeStart<TData> * myStart;
		SNode<TData> * myAct;
		int mySize;
	public:
		Set() {
			mySize = 0;
			myStart = new SNodeStart<TData>;
			myAct = 0;
		}
		
		virtual ~Set() {
			delete myStart;
		}
		
		virtual void AddData(TData * data) {
			myStart->AddNode(data);
			mySize++;
		}
		
		virtual void DeleteData(TData * data) {
			myStart->DeleteNode(data);
			mySize--;
		}
		
		virtual void ResetData() {
			myAct = myStart;
		}
		
		virtual TData * GetNextData() {
			if(myAct) myAct = myAct->GetNextNode();
			if(myAct) return myAct->GetNodeData();
			else return 0;
		}
		
		virtual int GetSize() { return mySize; }
};

template <typename TData> class SetEx : public Set<TData> {
	protected:
		int myLend;
	public:
		SetEx(): myLend(0) { }
		~SetEx() { }
		
		void Lend() {
			myLend++;
		}
		
		void Return() {
			myLend--;
		}
		
		int GenLend() {
			return myLend;
		}
};

#endif
