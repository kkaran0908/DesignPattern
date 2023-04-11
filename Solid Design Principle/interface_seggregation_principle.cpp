/*
the interface segregation principle (ISP) states 
that no code should be forced to depend on methods it 
does not use. ISP splits interfaces that are very large 
into smaller and more specific ones so that clients will
only have to know about the methods that are of interest to them.
*/

//1. Bad interface design
class Document;

class Machine {
public:
	virtual void print(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
};

class PrintingMachine: public Machine
{
//inside this we must provide only print function definition but
//due to the bad interface design we have to provide definition of scan and fax as well
};

//2. Good Interface design i.e. Seggregate the interface 

class iPrinter{
public:
	virtual void print(Document& doc) = 0;
};

class PrintingMachine: public iPrinter
{
public:
	//because of good interface design
	//we need not to provide the scan and fax function's definition
	void print(Document& doc) override;
};




