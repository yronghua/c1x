#pragma once

void r_value(int && i) {
	std::cout << "r value " << i << std::endl;
	++i;
	std::cout << "r value " << i << std::endl;
}

void r_value(int &i) {
	std::cout << "refrence value " << i << std::endl;
}

class CTestMove
{
public:
	CTestMove() {
		std::cout << "constructor" << std::endl;
	}

	CTestMove(int i) : i_(i) {
		std::cout << "contructor" << i << std::endl;
	}

	CTestMove(const CTestMove& r) {
		std::cout << "copy constructor" << std::endl;
		i_ = r.i_;
	}

	CTestMove(const CTestMove&& r) {
		std::cout << "rcopy constructor" << std::endl;
		i_ = r.i_;
	}

	void print() {
		std::cout << __FUNCTION__ << " " << i_ << std::endl;
	}

public:
	int i_;
};

CTestMove get_test()
{
	CTestMove temp;
	temp.i_ = 1;
	return temp;
}

CTestMove&& get_test_r(CTestMove* &temp)
{
	temp = new CTestMove;
	temp->i_ = 2;
	return std::move(*temp);
	/*
	CTestMove ret;
	ret.i_ = 3;
	temp = &ret;
	return std::move(ret);
	//*/
}

void test_move()
{
    LOG_FUNCTION;
	int i = 1;
	r_value(i);
	r_value(std::move(i));
	std::cout << "after call " << i << std::endl;

	CTestMove test_move = get_test();
	test_move.print();
	std::cout << std::endl;

	std::vector<CTestMove> vec_move;
	//vec_move.push_back(CTestMove(3));
	//vec_move.push_back(test_move);

	CTestMove *ptr_move = NULL;
	CTestMove&& r_move = get_test_r(ptr_move);
	ptr_move->print();
	r_move.print();
	vec_move.push_back(get_test_r(ptr_move));
	vec_move.push_back(r_move);	 // copy
	vec_move.push_back(std::move(r_move));  // rcopy
	//delete ptr_move;
	for (auto & it : vec_move) {
		it.print();
	}
}
