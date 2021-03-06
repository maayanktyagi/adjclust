/*
 *  PseudoMatrix.h
 *  PseudoMatrix
 *
 *  Created by Michel Koskas on 02/11/15.
 *  Copyright 2015 INRA, INA. All rights reserved.
 *
 */

#ifndef PseudoMatrix_h_
#define PseudoMatrix_h_

#include <assert.h>
#include "FusionnedClasses.h"
#include "ColsArray.h"
#include <map>
#include <set>

class ClassesHeap;

class FusionnedClasses;

class PseudoMatrix
{
public:
  PseudoMatrix();
  PseudoMatrix(double *V, int P, int H);
  void Initialize(double *V, int P, int H);
  void Fusion(int LineIndex, int &NumFusionnedClass);
  int NbFusions;
  int h;
  int p;
  ColsArray *MyData;
  // std::map<int, int> *WhichColumn;
	// std::set<int> *Free;
  // double *MyValues;
  FusionnedClasses *MyClasses;
  int NbClasses;
    // in next two funcitons, i and j are the initial index (without taking into account the fusions, without taking into account the C matric. They are the coordinates in the uintial A matrix p x p)
  double Value(int i, int j, int SupposedPlace) const;
  double Value(int i, int j) const;
  void Set(int LineInA, int ColumnInA, double v);
  void Set(int LineInA, int ColumnInA, double v, int ForceIndex, bool Assumption = false);
  void DisplayMatrixA(std::ostream &s) const;
  ~PseudoMatrix();

private:
  bool ElementOfAIsInC(int LineInA, int ColumnInA);
};

std::ostream &operator<<(std::ostream &s, const PseudoMatrix &M);




















#endif


