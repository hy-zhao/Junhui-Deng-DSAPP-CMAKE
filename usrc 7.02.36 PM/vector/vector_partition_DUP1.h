/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2020. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //轴点构造算法：通过调整元素位置构造区间[lo, hi)的轴点，并返回其秩
Rank Vector<T>::partition ( Rank lo, Rank hi ) { //DUP1版：与DUP版等价，类似于与LUG版等价的LUG1版
   swap ( _elem[lo], _elem[ lo + rand() % ( hi - lo ) ] ); //任选一个元素与首元素交换
   hi--; T pivot = _elem[lo]; //以首元素为候选轴点――经以上交换，等效于随机选取
   while ( lo < hi ) { //从向量的两端交替地向中间扫描
      while ( ( lo < hi ) && ( pivot < _elem[hi] ) ) //在大于pivot的前提下
         hi--; //向左拓展右端子向量
      if ( lo < hi ) _elem[lo++] = _elem[hi]; //不大于pivot者归入左端子向量
      while ( ( lo < hi ) && ( _elem[lo] < pivot ) ) //在小于pivot的前提下
         lo++; //向右拓展左端子向量
      if ( lo < hi ) _elem[hi--] = _elem[lo]; //不小于pivot者归入右端子向量
   } //assert: lo == hi
   _elem[lo] = pivot; //将备份的轴点记录置于前、后子向量之间
   return lo; //返回轴点的秩
}