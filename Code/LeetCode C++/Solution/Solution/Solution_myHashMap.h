#pragma once
#include "SolutionBase.h"
class MyHashMap {
	vector<int> data;
	vector<int> keyDict;
	int length = 10000;
	int hashFunc(int key)
	{
		return key % length;
	}

	int hashFunc1(int key)
	{
		return key % length;
	}

	int rehash(int key, int i)
	{
		return (hashFunc(key) + i*hashFunc1(key))%length;
	}
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		data = vector<int>(length, -1);
		keyDict = vector<int>(length, -1);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int ret = hashFunc(key);
		int i = 1;
		while (data[ret] >= 0)
		{
			if (keyDict[ret] == key || keyDict[ret] < 0)
			{
				keyDict[ret] = key;
				data[ret] = value;
				return;
			}	
			ret = rehash(key, i++);
		}
		keyDict[ret] = key;
		data[ret] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int ret = hashFunc(key);
		int i = 1;
		while (data[ret] >= 0)
		{
			if (keyDict[ret] == key)
			{
				return data[ret];
			}
			ret = rehash(key, i++);
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int ret = hashFunc(key);
		int i = 1;
		while (data[ret] >= 0)
		{
			if (keyDict[ret] == key)
			{
				keyDict[ret] = -1;
				data[ret] = -1;
				return;
			}
			ret = rehash(key, i++);
		}
	}
};

class Solution_myHashMap :SolutionBase {
public:
	void RunTest()
	{
		RunTestCase();
	}

	void RunTestCase()
	{
		MyHashMap hashMap = MyHashMap();
		hashMap.put(1, 1);
		hashMap.put(2, 2);
		hashMap.put(1, 3);
		hashMap.put(2, 4);
		cout<<hashMap.get(1)<<endl; // 返回 1
		cout<<hashMap.get(3)<<endl; // 返回 -1 (未找到)
		hashMap.put(2, 1); // 更新已有的值
		cout<<hashMap.get(2)<<endl; // 返回 1 
		hashMap.remove(2); // 删除键为2的数据
		cout<<hashMap.get(2)<<endl; // 返回 -1 (未找到) 
	}
};