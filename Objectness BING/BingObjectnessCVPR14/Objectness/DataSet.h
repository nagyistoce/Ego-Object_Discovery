#pragma once
#include "datasetvoc.h"

class DataSet : public DataSetVOC
{
public:
	DataSet(void);
	~DataSet(void);
	DataSet(CStr &wkDir);

	void initTrain(CStr &trainPath);
	void initTest(CStr &testPath);

	void loadAnnotationsTrain();
	void loadAnnotationsTest();

	friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<DataSetVOC>(*this);
		ar & imgPathTrain;
		ar & annoPathTrain;
		ar & imgPathTest;
		ar & annoPathTest;
	}

public:
	string imgPathTrain, annoPathTrain;
	string imgPathTest, annoPathTest;

};