#ifndef NODES_HPP
#define NODES_HPP

template <typename TData> class SNode {
	private:
		
	public:
		SNode() { }
		virtual ~SNode() { }
		
		virtual SNode<TData> * AddNode(TData * data) = 0;
		virtual SNode<TData> * DeleteNode(TData * data) = 0;
		virtual SNode<TData> * GetNextNode() = 0;
		virtual TData * GetNodeData() { return 0; }
		
};

template <typename TData> class SNodeData : public SNode<TData> {
	private:
		SNode<TData> * myNext;
		TData * myData;
	public:
		SNodeData(TData * data, SNode<TData> * next):
			myNext(next), myData(data) { }
			
		~SNodeData() {
			if(myNext)
				delete myNext;
		}
		
		SNode<TData> * AddNode(TData * data) {
			if((*data) < (*myData)) {
				SNodeData<TData> * tmp = new SNodeData<TData>(data, this);
				return tmp;
			} else {
				myNext = myNext->AddNode(data);
				return this;
			}
		}
		
		SNode<TData> * DeleteNode(TData * data) {
			if(data == myData) {
				SNode<TData> * tmp = myNext;
				myNext = 0; myData = 0;
				return tmp;
			} else {
				SNode<TData> * tmp = myNext;
				myNext = myNext->DeleteNode(data);
				if(myNext != tmp)
					delete tmp;
				return this;
			}
		}
		
		SNode<TData> * GetNextNode() {
			return myNext;
		}
		
		TData * GetNodeData() {
			return myData;
		}
};

template <typename TData> class SNodeEnd : public SNode<TData> {
	private:
	public:
		SNodeEnd() { }
		~SNodeEnd() { }
		
		SNode<TData> * AddNode(TData * data) {
			SNodeData<TData> * tmp = new SNodeData<TData>(data, this);
			return tmp;			
		}
		
		SNode<TData> * DeleteNode(TData * data) {
			return this;
		}
		
		SNode<TData> * GetNextNode() {
			return 0;
		}
};

template <typename TData> class SNodeStart : public SNode<TData> {
	private:
		SNode<TData> * myNext;
	public:
		SNodeStart() {
			myNext = new SNodeEnd<TData>();
		}
		
		~SNodeStart() {
			delete myNext;
		}
		
		SNode<TData> * AddNode(TData * data) {
			myNext = myNext->AddNode(data);
			return this;
		}
		
		SNode<TData> * DeleteNode(TData * data) {
			SNode<TData> * tmp = myNext;
			myNext = myNext->DeleteNode(data);
			if(myNext != tmp)
				delete tmp;
			return this;
		}
		
		SNode<TData> * GetNextNode() {
			return myNext;
		}
};
#endif
