#pragma once

namespace custom
{
	template<typename T>
	class List
	{
	public:
		List() : head(nullptr), tail(nullptr), mISize(0) {}
		~List();
		void PushBack(T value);
		void PushFront(T value);
		T PopBack();
		T PopFront();
		void Print();

		inline bool Empty() const { return mISize == 0 ? true : false; }

	private:
		struct Node
		{
			Node() = delete;
			Node(T value, Node* next, Node* prev) : mValue(value), mNext(next), mPrev(prev) {}
			T mValue;
			Node* mNext;
			Node* mPrev;
		};

		Node* head;
		Node* tail;
		int mISize;
	};

	template<typename T>
	void List<T>::PushBack(T value)
	{
		if (mISize == 0)
		{
			head = new Node(value, nullptr, nullptr);
			tail = head;
		}
		else
		{
			Node* last = tail;
			tail = new Node(value, nullptr, last);
			last->mNext = tail;
		}
		mISize++;
	}

	template<typename T>
	void List<T>::PushFront(T value)
	{
		if (head)
		{
			Node* temp = head;
			head = new Node(value, temp, nullptr);
			temp->mPrev = head;
		}
		else
		{
			head = new Node(value, nullptr, nullptr);
			tail = head;
		}
		mISize++;
	}

	template<typename T>
	T List<T>::PopFront()
	{
		T value;
		if (mISize != 0)
		{
			value = head->mValue;

			if (mISize > 1)
			{
				Node* next = head->mNext;
				delete head;
				next->mPrev = nullptr;
				head = next;
			}
			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			mISize--;
		}
		return value;
	}

	template<typename T>
	T List<T>::PopBack()
	{
		T value;
		if (mISize != 0)
		{
			value = tail->mValue;
			if (mISize > 1)
			{
				Node* prev = tail->mPrev;
				delete tail;
				prev->mNext = nullptr;
				tail = prev;
			}
			else
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			mISize--;
		}
		return value;
	}


	template<typename T>
	void List<T>::Print()
	{
		Node* temp = head;
		while (temp)
		{
			std::cout << temp->mValue << std::endl;
			temp = temp->mNext;
		}
	}


	template<typename T>
	List<T>::~List()
	{
		while (head)
		{
			Node* temp(head);
			head = head->mNext;
			delete temp;
		}
	}
}
