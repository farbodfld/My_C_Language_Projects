/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once

#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<float.h>
#include<algorithm>
#include<numeric>  //std::iota

#define XMIN 0
#define XMAX DBL_MAX
#define YMIN 0
#define YMAX DBL_MAX


using namespace std;

class Point {
public:
    double x;  // x-coordinate
    double y;  // y-coordinate

public:

    Point() : x(0), y(0) {}

    Point(double i) : x(i), y(i) {}

    Point(double a, double b) : x(a), y(b) {}

    ~Point() {}

    void put_value(double x_, double y_) {
        x = x_;
        y = y_;
    }

    double get_value(int d) {
        switch (d) {
            case 1:
                return x;
                break;
            case 2:
                return y;
                break;
            default:
                return -1;
        }
    }

    void display() {
        cout << "(" << x << "," << y << ")";
    }

    friend ostream &operator<<(ostream &output, Point &P) {
        output << "(" << P.x << "," << P.y << ")";
        return output;
    }

    bool operator==(const Point &P) const {
        return this->y == P.y;
    }

    bool operator<(const Point &P) const {
        return this->y < P.y;
    }


    static void rangequery(vector<Point> &data, Point from, Point to, vector<Point> &result) {
        result.clear();
        size_t i, n = data.size();
        for (i = 0; i < n; i++) {
            if (data[i].x >= from.x && data[i].x <= to.x && data[i].y >= from.y && data[i].y <= to.y)
                result.push_back(data[i]);
        }
    }
};


static void display(Point &p) {
    p.display();
}

static void displayint(size_t p) {

    cout << p << ",";
}


static bool xless(const Point &l, const Point &r) {
    return l.x < r.x;
}

static bool yless(const Point &l, const Point &r) {
    return l.y < r.y;
}

static bool xequal(const Point &l, const Point &r) {
    return l.x == r.x;
}

static bool yequal(const Point &l, const Point &r) {
    return l.y == r.y;
}

typedef bool (*CompFun)(const Point &, const Point &);


static bool issorted(const vector<Point> &V, CompFun comp) {
    int i;
//	cout<<int(V.size()-1)<<endl;
    for (i = 0; i < int(V.size() - 1); i++) {
        if (comp(V[i + 1], V[i])) return false;
    }
    return true;
}

static vector<Point> readfile(const string &filename) {
    vector<Point> origin;
    ifstream indata;

    indata.open(filename.data()); // opens the file
    if (!indata) { // file couldn't be opened
        cerr << "Error: file " << filename << " could not be opened" << endl;
        exit(1);
    }
    cout << "file " << filename << " is opened." << endl;


    double xin, yin;
    Point t;
    while (indata >> xin >> yin) {
        t.put_value(xin, yin);
        origin.push_back(t);
    };
    indata.close();
    return origin;
}

/*
struct node
{
	Point key;
	size_t index;
	bool operator<(const node& K)
	{
		return yless(key, K.key);
	}
};
static vector<size_t> sort_index(const vector<Point>& data)
{
	size_t n = data.size();
	vector<node> consdata(n);
	for (size_t i = 0; i < n; i++)
	{
		consdata[i].key = data[i];
		consdata[i].index = i;
	}
	sort(consdata.begin(), consdata.end());

	vector<size_t> outindex(n);
	for (size_t i = 0; i < n; i++)
	{
		outindex[i] = consdata[i].index;
	}
	return outindex;
}

static vector<size_t> sort_index(const vector<Point>& data, const vector<size_t>& index)
{
	size_t n = index.size();
	vector<node> consdata(n);
	for (size_t i = 0; i < n; i++)
	{
		consdata[i].key = data[index[i]];
		consdata[i].index = index[i];
	}
	sort(consdata.begin(), consdata.end());

	vector<size_t> outindex(n);
	for (size_t i = 0; i < n; i++)
	{
		outindex[i] = consdata[i].index;
	}
	return outindex;
}
*/

template<typename T>
vector<size_t> sort_index(const vector<T> &v, bool (*comp)(const T &, const T &)) {

    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
//    for(int i=0;i<v.size();i++)  idx[i]=i;


    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(), [&v, &comp](size_t i1, size_t i2) { return (*comp)(v[i1], v[i2]); });

    return idx;
}

template<typename T>
vector<size_t> sort_index(const vector<T> &v, vector<size_t> &idx) {
    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

    return idx;
}

template<typename T>
vector<size_t> sort_index(const vector<T> &v, vector<size_t> &idx, bool(*comp)(const T &, const T &)) {
    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(), [&v, &comp](size_t i1, size_t i2) { return (*comp)(v[i1], v[i2]); });

    return idx;
}


/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once

#include<vector>
//#include "point.h"

class indexrtFC {
    // constructor
public:
    indexrtFC(void);

    indexrtFC(vector<size_t> &index);

    indexrtFC(vector<Point> &indata);
    //destructor
public:
    ~indexrtFC(void);
    // member variable
public:
    size_t keypos;

    indexrtFC *lchild;
    indexrtFC *rchild;
    vector<size_t> lindex;   // data index in the left child data
    vector<size_t> rindex;   // data index in the righ child data
    vector<size_t> dataindex;   //the difference to rangetreeFC,  y order index

    static vector<Point> data;  //
    // member function
public:
//	void sortdata(int d);
//	size_t getsize();
    bool buildtree();

    void rangequery(Point &from, Point &to, vector<Point> &result);

    indexrtFC *find_split(Point &low, Point &high);

    void printtree();

    static void fcset(vector<size_t> &A1, vector<size_t> &A2, vector<size_t> &index,
                      CompFun less);   // set the index for fractional cascading
    static void intervalquery(vector<Point> &data, Point from, Point to, size_t &lo,
                              size_t &hi);  // interval query from the current node
    static size_t bsearch(Point &P, vector<size_t> &V);

//	static void inserttoresult(indexrtFC* datanode, size_t lo, size_t hi, vector<Point>& result);
    static void inserttoresult(indexrtFC *datanode, size_t lo, Point &to, vector<Point> &result);

    bool isleaf();  //whether this node is a leaf node
    static void indextransfer(vector<size_t> &index, size_t low, size_t high, size_t &newlow, size_t &newhigh);

    unsigned long long size();
//	vector<Point> indextodata(vector<size_t> index);

};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#include<algorithm>
//#include "indexrtFC.h"

vector<Point>  indexrtFC::data;

indexrtFC::indexrtFC(void) {
    size_t n = data.size();

//	for (size_t i = 0; i < n; i++) dataindex[i] = i;
//	iota(dataindex.begin(), dataindex.end(), 0);
    dataindex = sort_index(data, xless);

    keypos = dataindex[!(n % 2) ? (n / 2 - 1) : (n - 1) / 2];
    lindex.resize(n + 1, -1);
    rindex.resize(n + 1, -1);  // an additional size_t to store the end, it would be the size of the subvector.
    lchild = NULL;
    rchild = NULL;
}

indexrtFC::indexrtFC(vector<size_t> &index) {
    size_t n = index.size();

    dataindex = index;
    keypos = dataindex[!(n % 2) ? (n / 2 - 1) : (n - 1) / 2];
    lindex.resize(n + 1, -1);
    rindex.resize(n + 1, -1);  // an additional size_t to store the end, it would be the size of the subvector.
    lchild = NULL;
    rchild = NULL;
}

indexrtFC::indexrtFC(vector<Point> &indata) {
    data = indata;
    new(this) indexrtFC();
}


indexrtFC::~indexrtFC(void) {
    delete lchild;

    delete rchild;

}


bool indexrtFC::buildtree() {
    size_t n = dataindex.size();
    if (n == 0)
        return false;

    //	cout<<"\ncurrent point:";
    //	key.display();
    //	cout<<endl;
    if (n == 1) {
        lchild = NULL;
        rchild = NULL;
    } else {
        size_t pos = !(n % 2) ? n / 2 - 1 : (n - 1) / 2;
        vector<size_t> left, right;
        left.assign(dataindex.begin(), dataindex.begin() + pos + 1);
        right.assign(dataindex.begin() + pos + 1, dataindex.end());

        //		cout<<"\nbuilding left tree..."<<endl;
        lchild = new indexrtFC(left);
        lchild->buildtree();

        //		cout<<"\nbuilding right tree..."<<endl;
        rchild = new indexrtFC(right);
        rchild->buildtree();

        sort_index(data, dataindex);
        //sort_index(data, left);
        //sort_index(data, right);

        fcset(dataindex, lchild->dataindex, lindex, yless);
        fcset(dataindex, rchild->dataindex, rindex, yless);
    }

    return true;
}

void indexrtFC::printtree() {
    indexrtFC *T = this;
    if (T != NULL) {
        cout << "\nkey:";
        data[T->keypos].display();
        cout << "\ndata:";
        for_each(T->dataindex.begin(), T->dataindex.end(), displayint);
        cout << "\nlindex:";
        for_each(T->lindex.begin(), T->lindex.end(), displayint);
        cout << "\nrindex:";
        for_each(T->rindex.begin(), T->rindex.end(), displayint);
        cout << "L";
        T->lchild->printtree();
        cout << "R";
        T->rchild->printtree();
    }
}


//  A2  belong to A1
void indexrtFC::fcset(vector<size_t> &A1, vector<size_t> &A2, vector<size_t> &index, CompFun less) {
    size_t n1 = A1.size();
    size_t n2 = A2.size();
    size_t i = 0, j = 0;

    for (; j < n2; j++) {
        for (; i < n1; i++) {
            if (!less(data[A2[j]], data[A1[i]])) index[i] = j;
            else break;
        }
    }

}

void indexrtFC::rangequery(Point &from, Point &to, vector<Point> &result) {
    result.clear();
    indexrtFC *split = find_split(from, to);
    if (split == NULL) return;

    if (split->isleaf()) {
        auto sp = data[split->keypos];
        if (sp.y >= from.y && sp.y <= to.y) result.push_back(sp);
//		inserttoresult(split, lowdex, to, result);
        return;
    }

    size_t lowdex; //the interval in split
    lowdex = bsearch(from, split->dataindex);
    if (lowdex == -1) return;

    ////query point from
    indexrtFC *s = split->lchild;
    size_t low;  // the lowindex and highindex in subsets
    low = split->lindex[lowdex];

    if (low != -1) {
        if (from.x <= XMIN) {
            inserttoresult(s, low, to, result);
        } else {
            while (s != NULL) {
                if (!xless(data[s->keypos], from)) {
                    if (s->lchild == NULL && s->rchild == NULL)
                        inserttoresult(s, low, to, result);
                    else {
                        inserttoresult(s->rchild, s->rindex[low], to, result);
                    }

                    low = s->lindex[low];
                    if (low == -1) break;
                    s = s->lchild;
                } else {
                    low = s->rindex[low];
                    if (low == -1) break;
                    s = s->rchild;
                }
            }
        }
    }

    //query point to
    s = split->rchild;
    //	indextransfer(split->rindex,lowdex,hidex,low,high);
    low = split->rindex[lowdex];
    if (low != -1) {
        if (to.x >= XMAX) {
            inserttoresult(s, low, to, result);
        } else {
            while (s != NULL) {
                if (!xless(to, data[s->keypos])) {
                    if (s->lchild == NULL && s->rchild == NULL) {
                        inserttoresult(s, low, to, result);
                    } else {
                        inserttoresult(s->lchild, s->lindex[low], to, result);

                    }

                    low = s->rindex[low];
                    if (low == -1) break;
                    s = s->rchild;
                } else {
                    low = s->lindex[low];
                    if (low == -1) break;
                    s = s->lchild;
                }
            }
        }
    }
}

indexrtFC *indexrtFC::find_split(Point &low, Point &high) {
    //  if low is greater than high, swap them
    if (xless(high, low) || yless(high, low)) {
        return NULL;
    }

    // query
    indexrtFC *s = this;
    while (s != NULL) {
        if (xless(data[s->keypos], low)) {
            s = s->rchild;
        } else if (xless(high, data[s->keypos])) {
            s = s->lchild;
        } else {
            return s;
        }
    }
    return NULL;
}

// interval query from the current node, lo and hi is the index
void indexrtFC::intervalquery(vector<Point> &data, Point from, Point to, size_t &lo, size_t &hi) {
    //  if low is greater than high, swap them
    if (yless(to, from)) {
        Point temp = from;
        from = to;
        to = temp;
    }

//	lo = bsearch(from, data);
//	hi = bsearch(to, data);


    //if (lo==-1)   // the from position exceeds the end
    //{
    //	hi=-1;
    //	return;
    //}
    //size_t n=data.size();
    //size_t i=lo;
    //for(;i<n && !yless(to,data[i]);i++);

    //hi=i; // if hi<lo, the to position prior to the begin.


}

// return the first position where the value is not less than the given point P.
size_t indexrtFC::bsearch(Point &P, vector<size_t> &V) {
    // binary search
    size_t n = V.size();
    size_t l = 0;
    size_t h = n - 1;
    size_t m = h;
    while (int(l) <= int(h)) {
//		Point tl=data[V[l]];
//		Point th = data[V[h]];
//
//		if (P.y < tl.y) return l;
//		if (th.y < P.y)  return h + 1;
//		if (tl.y == th.y) return l;
//
//		m= l+ (P.y- tl.y)*(h-l) /(th.y- tl.y);
        m = (l + h) / 2;
        Point tm = data[V[m]];

        if (tm.y == P.y) {
            int i;
            for (i = m; int(i) >= 0; i--)    //  in case of some equal elements
            {
                if (data[V[i]].y != P.y) break;
            }
            return i + 1;
        }
        if (P.y < tm.y) h = m - 1;
        else l = m + 1;
    }
    if (h == m - 1) return m;
    else return m + 1 < n ? m + 1 : -1;    // if the position exceeds, return -1.
}

void indexrtFC::inserttoresult(indexrtFC *datanode, size_t lo, Point &to, vector<Point> &result) {

    if (datanode == NULL) return;
    if (lo == -1) return;

    vector<size_t> &V = datanode->dataindex;
    size_t i, n = V.size();


    //if (hi==-1)
    //{
    //	result.insert(result.end(),V.begin()+lo, V.end());
    //	return;
    //}
    //if(to.y>=V[hi].y)
    //{
    //size_t i=hi;
    //for(; i<n && V[i].y==V[hi].y;i++);
    //hi=i;
    //}
    //result.insert(result.end(),V.begin()+lo, V.begin()+hi);

    //	if (hi==-1)  hi=n;


    //for(i=lo;i<hi;i++)
    //{
    //	result.push_back(V[i]);
    //}

    for (i = lo; i < n && !yless(to, data[V[i]]); i++) {
        result.push_back(data[V[i]]);
    }


}

bool indexrtFC::isleaf() {
    if (lchild == NULL && rchild == NULL) return true;

    return false;
}

void indexrtFC::indextransfer(vector<size_t> &index, size_t low, size_t high, size_t &newlow, size_t &newhigh) {
    if (low == -1) {
        newlow = -1;
        return;
    }

    newlow = index[low];
    newhigh = (high == -1) ? -1 : index[high];


}

unsigned long long indexrtFC::size() {
    unsigned long long r = sizeof(*this);
    if (lchild != NULL) r += lchild->size();
    if (rchild != NULL) r += rchild->size();
    r += (lindex.capacity() + rindex.capacity() + dataindex.capacity()) * sizeof(size_t);
    return r;
}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once

#include<string>
//#include"point.h"

class Interval : public Point {
public:
    Interval(void);

    Interval(double i);

    Interval(double a, double b);

    Interval(Point Po);

public:
    ~Interval(void);
//public:
//	double x;  // the begin point
//	double y;  // the end point

public:
    //void put_value(double x_, double y_);
    void put_value(Point Po);

    void transform(string op, Point &from, Point &to);  //transform the interval query to point query using range tree
    bool operator<(const Interval &I);

    bool operator>(const Interval &I);
};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

//#include "interval.h"
using namespace std;


Interval::Interval() {}

Interval::Interval(double i) : Point(i) {}

Interval::Interval(double a, double b) : Point(a, b) {}

Interval::Interval(Point Po) {
    x = Po.x;
    y = Po.y;
}

Interval::~Interval() {}

//void Interval::put_value(double x_, double y_)
//{
//	x = x_;
//	y = y_;
//}

void Interval::put_value(Point Po) {
    x = Po.x;
    y = Po.y;
}


void Interval::transform(string op, Point &from, Point &to) {
    if (op == "o") {
        from.put_value(XMIN, x + 0.5);
        to.put_value(x - 0.5, y - 0.5);
        return;
    }          //    0<x'<x,  x<y'<y
    else if (op == "oi") {
        from.put_value(x + 0.5, y + 0.5);
        to.put_value(y - 0.5, XMAX);
        return;
    }   //
    else if (op == "d") {
        from.put_value(x + 0.5, x + 0.5);
        to.put_value(y - 0.5, y - 0.5);
        return;
    }
    else if (op == "di") {
        from.put_value(XMIN, y + 0.5);
        to.put_value(x - 0.5, XMAX);
        return;
    }
    else if (op == "m") {
        from.put_value(XMIN, x);
        to.put_value(x, x);
        return;
    }
    else if (op == "mi") {
        from.put_value(y, y);
        to.put_value(y, XMAX);
        return;
    }
    else if (op == "s") {
        from.put_value(x, x);
        to.put_value(x, y - 0.5);
        return;
    }
    else if (op == "si") {
        from.put_value(x, y + 0.5);
        to.put_value(x, XMAX);
        return;
    }
    else if (op == "f") {
        from.put_value(x + 0.5, y);
        to.put_value(y, y);
        return;
    }
    else if (op == "fi") {
        from.put_value(XMIN, y);
        to.put_value(x - 0.5, y);
        return;
    }
    else if (op == "<" || op == "p") {
        from.put_value(XMIN, XMIN);
        to.put_value(x - 0.5, x - 0.5);
        return;
    }
    else if (op == ">" || op == "pi") {
        from.put_value(y + 0.5, y + 0.5);
        to.put_value(XMAX, XMAX);
        return;
    }
    else if (op == "=" || op == "e") {
        from.put_value(x, y);
        to.put_value(x, y);
        return;
    }
    else { cout << "invalid relation" << endl; }
}

bool Interval::operator<(const Interval &I) {
    return x < I.x;
}

bool Interval::operator>(const Interval &I) {
    return x > I.x;
}

//file RBTree.h
#pragma once


#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

template<class KEY,class U>
class RB_Tree
{
private:
    RB_Tree(const RB_Tree& input){}
    const RB_Tree& operator=(const RB_Tree& input){}
public:
    enum COLOR{RED,BLACK};
    class RB_Node
    {
    public:
        RB_Node()
        {
            //RB_COLOR = BLACK;
            right = NULL;
            left = NULL;
            parent = NULL;
        }
        COLOR RB_COLOR;
        RB_Node* right;
        RB_Node* left;
        RB_Node* parent;
        KEY key;
        U data;
    };
public:
    RB_Tree()
    {
        this->m_nullNode = new RB_Node();
        this->m_root = m_nullNode;
        this->m_nullNode->right = this->m_root;
        this->m_nullNode->left = this->m_root;
        this->m_nullNode->parent = this->m_root;
        this->m_nullNode->RB_COLOR = BLACK;
    }

    bool Empty()
    {
        if(this->m_root == this->m_nullNode)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //²éصزkey
    RB_Node* find(KEY key)
    {
        RB_Node* index = m_root;
        while(index != m_nullNode)
        {
            if(key<index->key)
            {
                index  = index->left;  //±بµ±ا°µؤذ،£¬حù×َ
            }
            else if(key>index->key)
            {
                index = index->right;  //±بµ±ا°µؤ´َ£¬حùسز
            }
            else
            {
                break;
            }
        }
        return index;
    }

    //--------------------------²هبë½لµم×ـ²ظ×÷----------------------------------
    //ب«²؟µؤ¹¤×÷£¬¶¼شعدآتِخ±´ْآëضذ£؛
    /*RB-INSERT(T, z)
    1  y ،û nil[T]                 // y ت¼ضصض¸دٍ x µؤ¸¸½لµم،£
    2  x ،û root[T]              // x ض¸دٍµ±ا°ت÷µؤ¸ù½لµم£¬
    3  while x ،ظ nil[T]
    4      do y ،û x
    5         if key[z] < key[x]           //دٍ×َ£¬دٍسز..
    6            then x ،û left[x]
    7            else x ،û right[x]   //خھءثصزµ½؛دتتµؤ²هبëµم£¬xج½آ·¸ْ×ظآ·¾¶£¬ض±µ½x³ةخھNIL خھض¹،£
    8  p[z] ،û y         //yضأخھ ²هبë½لµمz µؤ¸¸½لµم،£
    9  if y = nil[T]
    10     then root[T] ،û z
    11     else if key[z] < key[y]
    12             then left[y] ،û z
    13             else right[y] ،û z     //´ث 8-13ذذ£¬ضأz دà¹طµؤض¸صë،£
    14  left[z] ،û nil[T]
    15  right[z] ،û nil[T]            //ةèخھ؟ص£¬
    16  color[z] ،û RED             //½«ذآ²هبëµؤ½لµمz×÷خھ؛ىة«
    17  RB-INSERT-FIXUP(T, z)
    */
    //زٍخھ½«z×إخھ؛ىة«£¬؟ةؤـ»لخ¥·´ؤ³ز»؛ى؛عذشضت£¬
    //ثùزشذèزھµ÷سأدآأوµؤRB-INSERT-FIXUP(T, z)ہ´±£³ض؛ى؛عذشضت،£
    bool Insert(KEY key,U data)
    {
        RB_Node* insert_point = m_nullNode;
        RB_Node* index = m_root;
        while(index!=m_nullNode)
        {
            insert_point = index;
            if(key<index->key)
            {
                index = index->left;
            }
            else if(key>index->key)
            {
                index = index->right;
            }
            else
            {
                return false;
            }
        }
        RB_Node* insert_node = new RB_Node();
        insert_node->key = key;
        insert_node->data = data;
        insert_node->RB_COLOR = RED;
        insert_node->right = m_nullNode;
        insert_node->left = m_nullNode;
        if(insert_point==m_nullNode) //بç¹û²هبëµؤتاز»؟إ؟صت÷
        {
            m_root = insert_node;
            m_root->parent = m_nullNode;
            m_nullNode->left = m_root;
            m_nullNode->right = m_root;
            m_nullNode->parent = m_root;
        }
        else
        {
            if(key<insert_point->key)
            {
                insert_point->left = insert_node;
            }
            else
            {
                insert_point->right = insert_node;
            }
            insert_node->parent = insert_point;
        }
        InsertFixUp(insert_node);    //µ÷سأInsertFixUpذق¸´؛ى؛عت÷ذشضت،£
    }

    //---------------------²هبë½لµمذشضتذق¸´--------------------------------
    //3ضض²هبëاé؟ِ£¬¶¼شعدآأوµؤخ±´ْآëضذ(خ´ةو¼°µ½ثùسذب«²؟µؤ²هبëاé؟ِ)،£
    /*
    RB-INSERT-FIXUP(T, z)
    1 while color[p[z]] = RED
    2     do if p[z] = left[p[p[z]]]
    3           then y ،û right[p[p[z]]]
    4                if color[y] = RED
    5                   then color[p[z]] ،û BLACK                    ? Case 1
    6                        color[y] ،û BLACK                       ? Case 1
    7                        color[p[p[z]]] ،û RED                   ? Case 1
    8                        z ،û p[p[z]]                            ? Case 1
    9                   else if z = right[p[z]]
    10                           then z ،û p[z]                       ? Case 2
    11                                LEFT-ROTATE(T, z)              ? Case 2
    12                           color[p[z]] ،û BLACK                 ? Case 3
    13                           color[p[p[z]]] ،û RED                ? Case 3
    14                           RIGHT-ROTATE(T, p[p[z]])            ? Case 3
    15           else (same as then clause with "right" and "left" exchanged)
    16 color[root[T]] ،û BLACK
    */
    //ب»؛َµؤ¹¤×÷£¬¾ح·ا³£¼ٍµ¥ءث£¬¼´°رةدتِخ±´ْآë¸ؤذ´خھدآتِµؤc++´ْآë£؛
    void InsertFixUp(RB_Node* node)
    {
        while(node->parent->RB_COLOR==RED)
        {
            if(node->parent==node->parent->parent->left)   //
            {
                RB_Node* uncle = node->parent->parent->right;
                if(uncle->RB_COLOR == RED)   //²هبëاé؟ِ1£¬zµؤتهتهyتا؛ىة«µؤ،£
                {
                    node->parent->RB_COLOR = BLACK;
                    uncle->RB_COLOR = BLACK;
                    node->parent->parent->RB_COLOR = RED;
                    node = node->parent->parent;
                }
                else if(uncle->RB_COLOR == BLACK )  //²هبëاé؟ِ2£؛zµؤتهتهyتا؛عة«µؤ£¬،£
                {
                    if(node == node->parent->right) //ازzتاسز؛¢×س
                    {
                        node = node->parent;
                        RotateLeft(node);
                    }
                    else                 //²هبëاé؟ِ3£؛zµؤتهتهyتا؛عة«µؤ£¬µ«zتا×َ؛¢×س،£
                    {
                        node->parent->RB_COLOR = BLACK;
                        node->parent->parent->RB_COLOR = RED;
                        RotateRight(node->parent->parent);
                    }
                }
            }
            else //صâ²؟·ضتاصë¶شخھ²هبëاé؟ِ1ضذ£¬zµؤ¸¸ا×دضشع×÷خھ×و¸¸µؤسز؛¢×سءثµؤاé؟ِ£¬¶ّذ´µؤ،£
                //15 else (same as then clause with "right" and "left" exchanged)
            {
                RB_Node* uncle = node->parent->parent->left;
                if(uncle->RB_COLOR == RED)
                {
                    node->parent->RB_COLOR = BLACK;
                    uncle->RB_COLOR = BLACK;
                    uncle->parent->RB_COLOR = RED;
                    node = node->parent->parent;
                }
                else if(uncle->RB_COLOR == BLACK)
                {
                    if(node == node->parent->left)
                    {
                        node = node->parent;
                        RotateRight(node);     //سëةدتِ´ْآëدà±ب£¬×َذ‎¸ؤخھسزذ‎
                    }
                    else
                    {
                        node->parent->RB_COLOR = BLACK;
                        node->parent->parent->RB_COLOR = RED;
                        RotateLeft(node->parent->parent);   //سزذ‎¸ؤخھ×َذ‎£¬¼´؟ة،£
                    }
                }
            }
        }
        m_root->RB_COLOR = BLACK;
    }

    //×َذ‎´ْآëتµدض
    bool RotateLeft(RB_Node* node)
    {
        if(node==m_nullNode || node->right==m_nullNode)
        {
            return false;//can't rotate
        }
        RB_Node* lower_right = node->right;
        lower_right->parent =  node->parent;
        node->right=lower_right->left;
        if(lower_right->left!=m_nullNode)
        {
            lower_right->left->parent = node;
        }
        if(node->parent==m_nullNode) //rotate node is root
        {
            m_root = lower_right;
            m_nullNode->left = m_root;
            m_nullNode->right= m_root;
            //m_nullNode->parent = m_root;
        }
        else
        {
            if(node == node->parent->left)
            {
                node->parent->left = lower_right;
            }
            else
            {
                node->parent->right = lower_right;
            }
        }
        node->parent = lower_right;
        lower_right->left = node;
    }

    //سزذ‎´ْآëتµدض
    bool RotateRight(RB_Node* node)
    {
        if(node==m_nullNode || node->left==m_nullNode)
        {
            return false;//can't rotate
        }
        RB_Node* lower_left = node->left;
        node->left = lower_left->right;
        lower_left->parent = node->parent;
        if(lower_left->right!=m_nullNode)
        {
            lower_left->right->parent = node;
        }
        if(node->parent == m_nullNode) //node is root
        {
            m_root = lower_left;
            m_nullNode->left = m_root;
            m_nullNode->right = m_root;
            //m_nullNode->parent = m_root;
        }
        else
        {
            if(node==node->parent->right)
            {
                node->parent->right = lower_left;
            }
            else
            {
                node->parent->left = lower_left;
            }
        }
        node->parent = lower_left;
        lower_left->right = node;
    }

    //--------------------------ة¾³‎½لµم×ـ²ظ×÷----------------------------------
    //خ±´ْآë£¬²»شظجù³ِ£¬دêاé£¬اë²خ؟¼´ث؛ى؛عت÷دµءذµع¶‏ئھخؤصآ£؛
    //¾­µنثم·¨رذ¾؟دµءذ£؛خه،¢؛ى؛عت÷ثم·¨µؤتµدضسëئتخِ£؛
    //http://blog.csdn.net/v_JULY_v/archive/2010/12/31/6109153.aspx،£
    bool Delete(KEY key)
    {
        RB_Node* delete_point = find(key);
        if(delete_point == m_nullNode)
        {
            return false;
        }
        if(delete_point->left!=m_nullNode && delete_point->right!=m_nullNode)
        {
            RB_Node* successor = InOrderSuccessor(delete_point);
            delete_point->data = successor->data;
            delete_point->key = successor->key;
            delete_point = successor;
        }
        RB_Node* delete_point_child;
        if(delete_point->right!=m_nullNode)
        {
            delete_point_child = delete_point->right;
        }
        else if(delete_point->left!=m_nullNode)
        {
            delete_point_child = delete_point->left;
        }
        else
        {
            delete_point_child = m_nullNode;
        }
        delete_point_child->parent = delete_point->parent;
        if(delete_point->parent==m_nullNode)//delete root node
        {
            m_root = delete_point_child;
            m_nullNode->parent = m_root;
            m_nullNode->left = m_root;
            m_nullNode->right = m_root;
        }
        else if(delete_point == delete_point->parent->right)
        {
            delete_point->parent->right = delete_point_child;
        }
        else
        {
            delete_point->parent->left = delete_point_child;
        }
        if(delete_point->RB_COLOR==BLACK && !(delete_point_child==m_nullNode && delete_point_child->parent==m_nullNode))
        {
            DeleteFixUp(delete_point_child);
        }
        delete delete_point;
        return true;
    }

    //---------------------ة¾³‎½لµمذشضتذق¸´-----------------------------------
    //ثùسذµؤ¹¤×÷£¬¶¼شعدآتِ23ذذخ±´ْآëضذ£؛
    /*
    RB-DELETE-FIXUP(T, x)
    1 while x ،ظ root[T] and color[x] = BLACK
    2     do if x = left[p[x]]
    3           then w ،û right[p[x]]
    4                if color[w] = RED
    5                   then color[w] ،û BLACK                        ?  Case 1
    6                        color[p[x]] ،û RED                       ?  Case 1
    7                        LEFT-ROTATE(T, p[x])                    ?  Case 1
    8                        w ،û right[p[x]]                         ?  Case 1
    9                if color[left[w]] = BLACK and color[right[w]] = BLACK
    10                   then color[w] ،û RED                          ?  Case 2
    11                        x p[x]                                  ?  Case 2
    12                   else if color[right[w]] = BLACK
    13                           then color[left[w]] ،û BLACK          ?  Case 3
    14                                color[w] ،û RED                  ?  Case 3
    15                                RIGHT-ROTATE(T, w)              ?  Case 3
    16                                w ،û right[p[x]]                 ?  Case 3
    17                         color[w] ،û color[p[x]]                 ?  Case 4
    18                         color[p[x]] ،û BLACK                    ?  Case 4
    19                         color[right[w]] ،û BLACK                ?  Case 4
    20                         LEFT-ROTATE(T, p[x])                   ?  Case 4
    21                         x ،û root[T]                            ?  Case 4
    22        else (same as then clause with "right" and "left" exchanged)
    23 color[x] ،û BLACK
    */
    //½سدآہ´µؤ¹¤×÷£¬؛ـ¼ٍµ¥£¬¼´°رةدتِخ±´ْآë¸ؤذ´³ةc++´ْآë¼´؟ة،£
    void DeleteFixUp(RB_Node* node)
    {
        while(node!=m_root && node->RB_COLOR==BLACK)
        {
            if(node == node->parent->left)
            {
                RB_Node* brother = node->parent->right;
                if(brother->RB_COLOR==RED)   //اé؟ِ1£؛xµؤذضµـwتا؛ىة«µؤ،£
                {
                    brother->RB_COLOR = BLACK;
                    node->parent->RB_COLOR = RED;
                    RotateLeft(node->parent);
                }
                else     //اé؟ِ2£؛xµؤذضµـwتا؛عة«µؤ£¬
                {
                    if(brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
                        //ازwµؤء©¸ِ؛¢×س¶¼تا؛عة«µؤ،£
                    {
                        brother->RB_COLOR = RED;
                        node = node->parent;
                    }
                    else if(brother->right->RB_COLOR == BLACK)
                        //اé؟ِ3£؛xµؤذضµـwتا؛عة«µؤ£¬wµؤسز؛¢×ستا؛عة«£¨wµؤ×َ؛¢×ستا؛ىة«£©،£
                    {
                        brother->RB_COLOR = RED;
                        brother->left->RB_COLOR = BLACK;
                        RotateRight(brother);
                    }
                    else if(brother->right->RB_COLOR == RED)
                        //اé؟ِ4£؛xµؤذضµـwتا؛عة«µؤ£¬ازwµؤسز؛¢×ست±؛ىة«µؤ،£
                    {
                        brother->RB_COLOR = node->parent->RB_COLOR;
                        node->parent->RB_COLOR = BLACK;
                        brother->right->RB_COLOR = BLACK;
                        RotateLeft(node->parent);
                        node = m_root;
                    }
                }
            }
            else  //دآتِاé؟ِصë¶شةدأوµؤاé؟ِ1ضذ£¬node×÷خھسز؛¢×س¶ّ²ûتِµؤ،£
                //22        else (same as then clause with "right" and "left" exchanged)
                //ح¬رù£¬ش­ہيز»ضآ£¬ض»تاسِµ½×َذ‎¸ؤخھسزذ‎£¬سِµ½سزذ‎¸ؤخھ×َذ‎£¬¼´؟ة،£ئنثü´ْآë²»±ن،£
            {
                RB_Node* brother = node->parent->left;
                if(brother->RB_COLOR == RED)
                {
                    brother->RB_COLOR = BLACK;
                    node->parent->RB_COLOR = RED;
                    RotateRight(node->parent);
                }
                else
                {
                    if(brother->left->RB_COLOR==BLACK && brother->right->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        node = node->parent;
                    }
                    else if(brother->left->RB_COLOR==BLACK)
                    {
                        brother->RB_COLOR = RED;
                        brother->right->RB_COLOR = BLACK;
                        RotateLeft(brother);
                    }
                    else if(brother->left->RB_COLOR==RED)
                    {
                        brother->RB_COLOR = node->parent->RB_COLOR;
                        node->parent->RB_COLOR = BLACK;
                        brother->left->RB_COLOR = BLACK;
                        RotateRight(node->parent);
                        node = m_root;
                    }
                }
            }
        }
        m_nullNode->parent = m_root;   //×î؛َ½«nodeضأخھ¸ù½لµم£¬
        node->RB_COLOR = BLACK;    //²¢¸ؤخھ؛عة«،£
    }

    //
    inline RB_Node* InOrderPredecessor(RB_Node* node)
    {
        if(node==m_nullNode)       //null node has no predecessor
        {
            return m_nullNode;
        }
        RB_Node* result = node->left;     //get node's left child
        while(result!=m_nullNode)         //try to find node's left subtree's right most node
        {
            if(result->right!=m_nullNode)
            {
                result = result->right;
            }
            else
            {
                break;
            }
        }            //after while loop result==null or result's right child is null
        if(result==m_nullNode)
        {
            RB_Node* index = node->parent;
            result = node;
            while(index!=m_nullNode && result == index->left)
            {
                result = index;
                index = index->parent;
            }
            result = index;         // first right parent or null
        }
        return result;
    }

    //
    inline RB_Node* InOrderSuccessor(RB_Node* node)
    {
        if(node==m_nullNode)       //null node has no successor
        {
            return m_nullNode;
        }
        RB_Node* result = node->right;   //get node's right node
        while(result!=m_nullNode)        //try to find node's right subtree's left most node
        {
            if(result->left!=m_nullNode)
            {
                result = result->left;
            }
            else
            {
                break;
            }
        }                              //after while loop result==null or result's left child is null
        if(result == m_nullNode)
        {
            RB_Node* index = node->parent;
            result = node;
            while(index!=m_nullNode && result == index->right)
            {
                result = index;
                index = index->parent;
            }
            result = index;         //first parent's left or null
        }
        return result;
    }

    //debug
    void InOrderTraverse()
    {
        InOrderTraverse(m_root);
    }
    void CreateGraph(string filename)
    {
        //delete
    }
    void InOrderCreate(ofstream& file,RB_Node* node)
    {
        //delete
    }
    void InOrderTraverse(RB_Node* node)
    {
        if(node==m_nullNode)
        {
            return;
        }
        else
        {
            InOrderTraverse(node->left);
            cout<<node->key<<endl;
            InOrderTraverse(node->right);
        }
    }
    ~RB_Tree()
    {
        clear(m_root);
        delete m_nullNode;
    }
private:
    // utility function for destructor to destruct object;
    void clear(RB_Node* node)
    {
        if(node==m_nullNode)
        {
            return ;
        }
        else
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
public:
    RB_Node *m_nullNode;
    RB_Node *m_root;
};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once

#include <vector>
//#include "RBtree.h"
//#include "interval.h"

using namespace std;

struct extinfo
{
    vector<Interval> equkey;  // interval with equal begins.
    double maxvalue;     // the max value in the subtree.

    extinfo()
    {
        equkey.clear();
        maxvalue = 0;
    }
};

class intervaltree: public RB_Tree<double,extinfo>
{
public:
    void Insert(Interval interv);
    void InsertFixUp(RB_Node* node);
    void buildtree(vector<Interval>& data);
    void buildtree(vector<Point>& data);
    void printtree(RB_Node* node);
    void printtree();
    unsigned long long  size(RB_Node* node);
    bool RotateLeft(RB_Node* node);
    bool RotateRight(RB_Node* node);
    void InOrderTraverse(RB_Node* node, vector<Interval>& result);
    void search_o(RB_Node* node, Interval i, vector<Interval>& result);
    void search_oi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_d(RB_Node* node, Interval i, vector<Interval>& result);
    void search_di(RB_Node* node, Interval i, vector<Interval>& result);
    void search_p(RB_Node* node, Interval i, vector<Interval>& result);
    void search_pi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_s(RB_Node* node, Interval i, vector<Interval>& result);
    void search_si(RB_Node* node, Interval i, vector<Interval>& result);
    void search_f(RB_Node* node, Interval i, vector<Interval>& result);
    void search_fi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_m(RB_Node* node, Interval i, vector<Interval>& result);
    void search_mi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_e(RB_Node* node, Interval i, vector<Interval>& result);
};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

//#include"intervaltree.h"
#include<algorithm>


void intervaltree::Insert(Interval interv)
{
    double key = interv.x;
    RB_Node* insert_point = m_nullNode;
    RB_Node* index = m_root;
    while (index != m_nullNode)
    {
        insert_point = index;
        if (index->data.maxvalue < interv.y)
        {
            index->data.maxvalue = interv.y;
        }
        if (key<index->key)
        {
            index = index->left;
        }
        else if (key>index->key)
        {
            index = index->right;
        }
        else
        {
            index->data.equkey.push_back(interv);
            return ;
        }
    }
    RB_Node* insert_node = new RB_Node();
    insert_node->key = key;
    insert_node->data.equkey.push_back(interv);
    insert_node->data.maxvalue = interv.y;
    insert_node->RB_COLOR = RED;
    insert_node->right = m_nullNode;
    insert_node->left = m_nullNode;
    if (insert_point == m_nullNode) //ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ز»ï؟½إ؟ï؟½ï؟½ï؟½
    {
        m_root = insert_node;
        m_root->parent = m_nullNode;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
        m_nullNode->parent = m_root;
    }
    else
    {
        if (key<insert_point->key)
        {
            insert_point->left = insert_node;
        }
        else
        {
            insert_point->right = insert_node;
        }
        insert_node->parent = insert_point;
    }

    InsertFixUp(insert_node);    //ï؟½ï؟½ï؟½ï؟½InsertFixUpï؟½ق¸ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ت،ï؟½
}

void intervaltree::InsertFixUp(RB_Node* node)
{
    while (node->parent->RB_COLOR == RED)
    {
        if (node->parent == node->parent->parent->left)   //
        {
            RB_Node* uncle = node->parent->parent->right;
            if (uncle->RB_COLOR == RED)   //ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½1ï؟½ï؟½zï؟½ï؟½ï؟½ï؟½ï؟½ï؟½yï؟½ا؛ï؟½ة«ï؟½ؤ،ï؟½
            {
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                node->parent->parent->RB_COLOR = RED;
                node = node->parent->parent;
            }
            else if (uncle->RB_COLOR == BLACK)  //ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½2ï؟½ï؟½zï؟½ï؟½ï؟½ï؟½ï؟½ï؟½yï؟½ا؛ï؟½ة«ï؟½ؤ£ï؟½ï؟½ï؟½
            {
                if (node == node->parent->right) //ï؟½ï؟½zï؟½ï؟½ï؟½ز؛ï؟½ï؟½ï؟½
                {
                    node = node->parent;
                    RotateLeft(node);
                }
                else                 //ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½3ï؟½ï؟½zï؟½ï؟½ï؟½ï؟½ï؟½ï؟½yï؟½ا؛ï؟½ة«ï؟½ؤ£ï؟½ï؟½ï؟½zï؟½ï؟½ï؟½ï؟½ï؟½س،ï؟½
                {
                    node->parent->RB_COLOR = BLACK;
                    node->parent->parent->RB_COLOR = RED;
                    RotateRight(node->parent->parent);
                }
            }
        }
        else //ï؟½â²؟ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½خھï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½1ï؟½ذ£ï؟½zï؟½ؤ¸ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½خھï؟½و¸¸ï؟½ï؟½ï؟½ز؛ï؟½ï؟½ï؟½ï؟½ثµï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ذ´ï؟½ؤ،ï؟½
            //15 else (same as then clause with "right" and "left" exchanged)
        {
            RB_Node* uncle = node->parent->parent->left;
            if (uncle->RB_COLOR == RED)
            {
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                uncle->parent->RB_COLOR = RED;
                node = node->parent->parent;
            }
            else if (uncle->RB_COLOR == BLACK)
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    RotateRight(node);     //ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ب£ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½خھï؟½ï؟½ï؟½ï؟½
                }
                else
                {
                    node->parent->RB_COLOR = BLACK;
                    node->parent->parent->RB_COLOR = RED;
                    RotateLeft(node->parent->parent);   //ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½خھï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ï؟½ة،ï؟½
                }
            }
        }
    }
    m_root->RB_COLOR = BLACK;
}

void intervaltree::buildtree(vector<Interval>& data)
{
    for (size_t i = 0; i < data.size(); i++)
        Insert(data[i]);
}

void intervaltree::buildtree(vector<Point>& data)
{
    for (size_t i = 0; i < data.size(); i++)
        Insert(Interval(data[i]));
}

void intervaltree::printtree(RB_Node* node)
{
    if (node != m_nullNode)
    {
        for_each(node->data.equkey.begin(), node->data.equkey.end(),display);
        cout << "color" << node->RB_COLOR << "  max" << node->data.maxvalue << endl;
        cout << "L";
        printtree(node->left);
        cout << "R";
        printtree(node->right);
    }
    else
    {
        cout << "leaf" << endl;
    }
}

void intervaltree::printtree()
{
    printtree(m_root);
}

bool intervaltree::RotateLeft(RB_Node* node)
{
    if (node == m_nullNode || node->right == m_nullNode)
    {
        return false;//can't rotate
    }
    RB_Node* lower_right = node->right;
    lower_right->parent = node->parent;
    node->right = lower_right->left;
    if (lower_right->left != m_nullNode)
    {
        lower_right->left->parent = node;
    }
    if (node->parent == m_nullNode) //rotate node is root
    {
        m_root = lower_right;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
        //m_nullNode->parent = m_root;
    }
    else
    {
        if (node == node->parent->left)
        {
            node->parent->left = lower_right;
        }
        else
        {
            node->parent->right = lower_right;
        }
    }
    node->parent = lower_right;
    lower_right->left = node;

    lower_right->data.maxvalue = node->data.maxvalue;
    Interval M = *max_element(node->data.equkey.begin(), node->data.equkey.end(), yless);
    node->data.maxvalue = max(max(node->left->data.maxvalue, node->right->data.maxvalue), double(M.y));
    return true;
}

bool intervaltree::RotateRight(RB_Node* node)
{
    if (node == m_nullNode || node->left == m_nullNode)
    {
        return false;//can't rotate
    }
    RB_Node* lower_left = node->left;
    node->left = lower_left->right;
    lower_left->parent = node->parent;
    if (lower_left->right != m_nullNode)
    {
        lower_left->right->parent = node;
    }
    if (node->parent == m_nullNode) //node is root
    {
        m_root = lower_left;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
        //m_nullNode->parent = m_root;
    }
    else
    {
        if (node == node->parent->right)
        {
            node->parent->right = lower_left;
        }
        else
        {
            node->parent->left = lower_left;
        }
    }
    node->parent = lower_left;
    lower_left->right = node;

    lower_left->data.maxvalue = node->data.maxvalue;
    Interval M = *max_element(node->data.equkey.begin(), node->data.equkey.end(), yless);
    node->data.maxvalue = max(max(node->left->data.maxvalue, node->right->data.maxvalue), double(M.y));
    return true;
}

void intervaltree::InOrderTraverse(RB_Node* node, vector<Interval>& result)
{
    if (node == m_nullNode)
    {
        return;
    }

    InOrderTraverse(node->left,result);

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        result.push_back(node->data.equkey[j]);
    }

    InOrderTraverse(node->right,result);

}

void intervaltree::search_o(RB_Node* node,Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.x) return;

    if (node->key >= i.x)
    {
        search_o(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t > i.x && t < i.y)
            result.push_back(node->data.equkey[j]);
    }

    search_o(node->left, i, result);
    search_o(node->right, i, result);
}

void intervaltree::search_oi(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.y) return;

    if (node->key <= i.x)
    {
        search_oi(node->right, i, result);
        return;
    }
    if (node->key >= i.y)
    {
        search_oi(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t > i.y)
            result.push_back(node->data.equkey[j]);
    }

    search_oi(node->left, i, result);
    search_oi(node->right, i, result);
}

void intervaltree::search_d(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.x) return;
    if (node->key <= i.x)
    {
        search_d(node->right, i, result);
        return;
    }
    if (node->key >= i.y)
    {
        search_d(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t < i.y)
            result.push_back(node->data.equkey[j]);
    }

    search_d(node->left, i, result);
    search_d(node->right, i, result);
}

void intervaltree::search_di(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.y) return;

    if (node->key >= i.x)
    {
        search_di(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t > i.y)
            result.push_back(node->data.equkey[j]);
    }

    search_di(node->left, i, result);
    search_di(node->right, i, result);
}

void intervaltree::search_p(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x)
    {
        InOrderTraverse(node, result);
        return;
    }
    if (node->key >= i.x)
    {
        search_p(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t < i.x)
            result.push_back(node->data.equkey[j]);
    }

    search_p(node->left, i, result);
    search_p(node->right, i, result);
}

void intervaltree::search_pi(RB_Node* node, Interval i, vector<Interval>& result)
{
    RB_Node* index = node;
    while (index != m_nullNode)
    {
        if (i.y >= index->key)
            index = index->right;
        else
        {
            for (size_t j = 0; j < index->data.equkey.size(); j++)
            {
                result.push_back(index->data.equkey[j]);
            }
            InOrderTraverse(index->right, result);
            index = index->left;
        }
    }
}

void intervaltree::search_s(RB_Node* nd, Interval i, vector<Interval>& result)
{
    RB_Node* node = find(i.x);
    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t < i.y)
            result.push_back(node->data.equkey[j]);
    }
}

void intervaltree::search_si(RB_Node* nd, Interval i, vector<Interval>& result)
{
    RB_Node* node = find(i.x);
    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t > i.y)
            result.push_back(node->data.equkey[j]);
    }
}

void intervaltree::search_f(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.y) return;
    if (node->key <= i.x)
    {
        search_f(node->right, i, result);
        return;
    }
    if (node->key >= i.y)
    {
        search_f(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t == i.y)
            result.push_back(node->data.equkey[j]);
    }

    search_f(node->left, i, result);
    search_f(node->right, i, result);
}

void intervaltree::search_fi(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.y) return;

    if (node->key >= i.x)
    {
        search_fi(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t == i.y)
            result.push_back(node->data.equkey[j]);
    }

    search_fi(node->left, i, result);
    search_fi(node->right, i, result);
}

void intervaltree::search_m(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x) return;

    if (node->key > i.x)
    {
        search_m(node->left, i, result);
        return;
    }

    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t == i.x)
            result.push_back(node->data.equkey[j]);
    }

    search_m(node->left, i, result);
    search_m(node->right, i, result);
}

void intervaltree::search_mi(RB_Node* nd, Interval i, vector<Interval>& result)
{
    RB_Node* node = find(i.y);
    result = node->data.equkey;
    //for (size_t j = 0; j < node->data.equkey.size(); j++)
    //{
    //		result.push_back(node->data.equkey[j]);
    //}
}

void intervaltree::search_e(RB_Node* nd, Interval i, vector<Interval>& result)
{
    RB_Node* node = find(i.x);
    for (size_t j = 0; j < node->data.equkey.size(); j++)
    {
        double t = node->data.equkey[j].y;
        if (t == i.y)
            result.push_back(node->data.equkey[j]);
    }
}

unsigned long long  intervaltree::size(RB_Node* node)
{
    if (node == m_nullNode)
    {
        return 0;
    }

    unsigned long long r = sizeof(*node);
    r+=size(node->left);
    r += size(node->right);
    r += node->data.equkey.capacity() * sizeof(Interval);
    return r;
}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once
#include <vector>
//#include "RBtree.h"
//#include "interval.h"

using namespace std;

struct extinfo_dp
{
    Interval itv;  // interval
    double maxvalue;     // the max value in the subtree.

    extinfo_dp()
    {
        maxvalue = 0;
    }
};

class itvtree :
        public RB_Tree<double, extinfo_dp>
{
public:
    itvtree();
    ~itvtree();
public:
    void Insert(Interval interv);
    void InsertFixUp(RB_Node* node);
    void buildtree(vector<Interval>& data);
    void buildtree(vector<Point>& data);
    void printtree(RB_Node* node);
    void printtree();
//	unsigned long long  size(RB_Node* node);
    bool RotateLeft(RB_Node* node);
    bool RotateRight(RB_Node* node);
    void InOrderTraverse(RB_Node* node, vector<Interval>& result);
    void search_o(RB_Node* node, Interval i, vector<Interval>& result);
    void search_oi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_d(RB_Node* node, Interval i, vector<Interval>& result);
    void search_di(RB_Node* node, Interval i, vector<Interval>& result);
    void search_p(RB_Node* node, Interval i, vector<Interval>& result);
    void search_pi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_s(RB_Node* node, Interval i, vector<Interval>& result);
    void search_si(RB_Node* node, Interval i, vector<Interval>& result);
    void search_f(RB_Node* node, Interval i, vector<Interval>& result);
    void search_fi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_m(RB_Node* node, Interval i, vector<Interval>& result);
    void search_mi(RB_Node* node, Interval i, vector<Interval>& result);
    void search_e(RB_Node* node, Interval i, vector<Interval>& result);
};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

//#include "itvtree.h"



itvtree::itvtree()
{
}


itvtree::~itvtree()
{
}

void itvtree::Insert(Interval interv)
{
    double key = interv.x;
    RB_Node* insert_point = m_nullNode;
    RB_Node* index = m_root;
    while (index != m_nullNode)
    {
        insert_point = index;
        if (index->data.maxvalue < interv.y)
        {
            index->data.maxvalue = interv.y;
        }
        if (key<index->key)
        {
            index = index->left;
        }
        else
        {
            index = index->right;
        }
    }
    RB_Node* insert_node = new RB_Node();
    insert_node->key = key;
    insert_node->data.itv=interv;
    insert_node->data.maxvalue = interv.y;
    insert_node->RB_COLOR = RED;
    insert_node->right = m_nullNode;
    insert_node->left = m_nullNode;
    insert_node->parent = insert_point;
    if (insert_point == m_nullNode) //أˆأ§آ¹أ»آ²أ¥أˆأ«آµأ„أٹأ‡أ’آ»آ؟أ…آ؟أ•أٹأ·
    {
        m_root = insert_node;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
        m_nullNode->parent = m_root;
    }
    else
    {
        if (key<insert_point->key)
        {
            insert_point->left = insert_node;
        }
        else
        {
            insert_point->right = insert_node;
        }
    }
    InsertFixUp(insert_node);    //آµأ·أ“أƒInsertFixUpأگأ‍آ¸آ´آ؛أ¬آ؛أڑأٹأ·أگأ”أ–أٹآ،آ£
}

void itvtree::InsertFixUp(RB_Node* node)
{
    while (node->parent->RB_COLOR == RED)
    {
        if (node->parent == node->parent->parent->left)   //
        {
            RB_Node* uncle = node->parent->parent->right;
            if (uncle->RB_COLOR == RED)   //آ²أ¥أˆأ«أ‡أ©آ؟أ¶1آ£آ¬zآµأ„أٹأ¥أٹأ¥yأٹأ‡آ؛أ¬أ‰آ«آµأ„آ،آ£
            {
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                node->parent->parent->RB_COLOR = RED;
                node = node->parent->parent;
            }
            else if (uncle->RB_COLOR == BLACK)  //آ²أ¥أˆأ«أ‡أ©آ؟أ¶2آ£آ؛zآµأ„أٹأ¥أٹأ¥yأٹأ‡آ؛أڑأ‰آ«آµأ„آ£آ¬آ،آ£
            {
                if (node == node->parent->right) //أ‡أ’zأٹأ‡أ“أ’آ؛آ¢أ—أ“
                {
                    node = node->parent;
                    RotateLeft(node);
                }
                else                 //آ²أ¥أˆأ«أ‡أ©آ؟أ¶3آ£آ؛zآµأ„أٹأ¥أٹأ¥yأٹأ‡آ؛أڑأ‰آ«آµأ„آ£آ¬آµآ«zأٹأ‡أ—أ³آ؛آ¢أ—أ“آ،آ£
                {
                    node->parent->RB_COLOR = BLACK;
                    node->parent->parent->RB_COLOR = RED;
                    RotateRight(node->parent->parent);
                }
            }
        }
        else //أ•أ¢آ²آ؟آ·أ–أٹأ‡أ•أ«آ¶أ”أژآھآ²أ¥أˆأ«أ‡أ©آ؟أ¶1أ–أگآ£آ¬zآµأ„آ¸آ¸أ‡أ—أڈأ–أ”أڑأ—أ·أژآھأ—أ¦آ¸آ¸آµأ„أ“أ’آ؛آ¢أ—أ“أپأ‹آµأ„أ‡أ©آ؟أ¶آ£آ¬آ¶أ¸أگآ´آµأ„آ،آ£
            //15 else (same as then clause with "right" and "left" exchanged)
        {
            RB_Node* uncle = node->parent->parent->left;
            if (uncle->RB_COLOR == RED)
            {
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                uncle->parent->RB_COLOR = RED;
                node = node->parent->parent;
            }
            else if (uncle->RB_COLOR == BLACK)
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    RotateRight(node);     //أ“أ«أ‰أڈأٹأ¶آ´أ؛أ‚أ«أڈأ آ±أˆآ£آ¬أ—أ³أگأ½آ¸أ„أژآھأ“أ’أگأ½
                }
                else
                {
                    node->parent->RB_COLOR = BLACK;
                    node->parent->parent->RB_COLOR = RED;
                    RotateLeft(node->parent->parent);   //أ“أ’أگأ½آ¸أ„أژآھأ—أ³أگأ½آ£آ¬آ¼آ´آ؟أ‰آ،آ£
                }
            }
        }
    }
    m_root->RB_COLOR = BLACK;
}

void itvtree::buildtree(vector<Interval>& data)
{
    for (size_t i = 0; i < data.size(); i++)
        Insert(data[i]);
}

void itvtree::buildtree(vector<Point>& data)
{
    for (size_t i = 0; i < data.size(); i++)
        Insert(Interval(data[i]));
}

void itvtree::printtree(RB_Node* node)
{
    if (node != m_nullNode)
    {
        node->data.itv.display();
        cout << "color" << node->RB_COLOR << "  max" << node->data.maxvalue << endl;
        cout << "L";
        printtree(node->left);
        cout << "R";
        printtree(node->right);
    }
    else
    {
        cout << "leaf" << endl;
    }
}

void itvtree::printtree()
{
    printtree(m_root);
}

bool itvtree::RotateLeft(RB_Node* node)
{
    if (node == m_nullNode || node->right == m_nullNode)
    {
        return false;//can't rotate
    }
    RB_Node* lower_right = node->right;
    lower_right->parent = node->parent;
    node->right = lower_right->left;
    if (lower_right->left != m_nullNode)
    {
        lower_right->left->parent = node;
    }
    if (node->parent == m_nullNode) //rotate node is root
    {
        m_root = lower_right;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
        //m_nullNode->parent = m_root;
    }
    else
    {
        if (node == node->parent->left)
        {
            node->parent->left = lower_right;
        }
        else
        {
            node->parent->right = lower_right;
        }
    }
    node->parent = lower_right;
    lower_right->left = node;

    lower_right->data.maxvalue = node->data.maxvalue;
    node->data.maxvalue = max(max(node->left->data.maxvalue, node->right->data.maxvalue), node->data.itv.y);
    return true;
}

bool itvtree::RotateRight(RB_Node* node)
{
    if (node == m_nullNode || node->left == m_nullNode)
    {
        return false;//can't rotate
    }
    RB_Node* lower_left = node->left;
    node->left = lower_left->right;
    lower_left->parent = node->parent;
    if (lower_left->right != m_nullNode)
    {
        lower_left->right->parent = node;
    }
    if (node->parent == m_nullNode) //node is root
    {
        m_root = lower_left;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
        //m_nullNode->parent = m_root;
    }
    else
    {
        if (node == node->parent->right)
        {
            node->parent->right = lower_left;
        }
        else
        {
            node->parent->left = lower_left;
        }
    }
    node->parent = lower_left;
    lower_left->right = node;

    lower_left->data.maxvalue = node->data.maxvalue;
    node->data.maxvalue = max(max(node->left->data.maxvalue, node->right->data.maxvalue), node->data.itv.y);
    return true;
}

void itvtree::InOrderTraverse(RB_Node* node, vector<Interval>& result)
{
    if (node == m_nullNode)
    {
        return;
    }

    InOrderTraverse(node->left, result);
    result.push_back(node->data.itv);
    InOrderTraverse(node->right, result);

}

void itvtree::search_o(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.x) return;

    if (node->key >= i.x)
    {
        search_o(node->left, i, result);
        return;
    }

    if (node->data.itv.y > i.x && node->data.itv.y < i.y)
        result.push_back(node->data.itv);

    search_o(node->left, i, result);
    search_o(node->right, i, result);
}

void itvtree::search_oi(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.y) return;

    if (node->key <= i.x)
    {
        search_oi(node->right, i, result);
        return;
    }
    if (node->key >= i.y)
    {
        search_oi(node->left, i, result);
        return;
    }

    if ( node->data.itv.y > i.y)
        result.push_back(node->data.itv);

    search_oi(node->left, i, result);
    search_oi(node->right, i, result);
}

void itvtree::search_d(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.x) return;
    if (node->key <= i.x)
    {
        search_d(node->right, i, result);
        return;
    }
    if (node->key >= i.y)
    {
        search_d(node->left, i, result);
        return;
    }

    if (node->data.itv.y > i.x && node->data.itv.y < i.y)
        result.push_back(node->data.itv);

    search_d(node->left, i, result);
    search_d(node->right, i, result);
}

void itvtree::search_di(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue <= i.y) return;

    if (node->key >= i.x)
    {
        search_di(node->left, i, result);
        return;
    }

    if (node->data.itv.y > i.y)
        result.push_back(node->data.itv);

    search_di(node->left, i, result);
    search_di(node->right, i, result);
}

void itvtree::search_p(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x)
    {
        InOrderTraverse(node, result);
        return;
    }
    if (node->key >= i.x)
    {
        search_p(node->left, i, result);
        return;
    }

    if (node->data.itv.y < i.x)
        result.push_back(node->data.itv);

    search_p(node->left, i, result);
    search_p(node->right, i, result);
}

void itvtree::search_pi(RB_Node* node, Interval i, vector<Interval>& result)
{
    auto index = node;
    while (index != m_nullNode)
    {
        if (i.y >= index->key)
            index = index->right;
        else
        {
            result.push_back(index->data.itv);
            InOrderTraverse(index->right, result);
            index = index->left;
        }
    }
}

void itvtree::search_s(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x) return;

    if (node->key < i.x)
    {
        search_s(node->right, i, result);
        return;
    }
    if (node->key > i.x)
    {
        search_s(node->left, i, result);
        return;
    }

    if (node->data.itv.y < i.y)
        result.push_back(node->data.itv);

    search_s(node->left, i, result);
    search_s(node->right, i, result);
}

void itvtree::search_si(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x) return;

    if (node->key < i.x)
    {
        search_si(node->right, i, result);
        return;
    }
    if (node->key > i.x)
    {
        search_si(node->left, i, result);
        return;
    }

    if (node->data.itv.y > i.y)
        result.push_back(node->data.itv);

    search_si(node->left, i, result);
    search_si(node->right, i, result);
}

void itvtree::search_f(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.y) return;
    if (node->key <= i.x)
    {
        search_f(node->right, i, result);
        return;
    }
    if (node->key >= i.y)
    {
        search_f(node->left, i, result);
        return;
    }

    if (node->data.itv.y == i.y)
        result.push_back(node->data.itv);

    search_f(node->left, i, result);
    search_f(node->right, i, result);
}

void itvtree::search_fi(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.y) return;

    if (node->key >= i.x)
    {
        search_fi(node->left, i, result);
        return;
    }

    if (node->data.itv.y == i.y)
        result.push_back(node->data.itv);

    search_fi(node->left, i, result);
    search_fi(node->right, i, result);
}

void itvtree::search_m(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x) return;

    if (node->key > i.x)
    {
        search_m(node->left, i, result);
        return;
    }

    if (node->data.itv.y == i.x)
        result.push_back(node->data.itv);

    search_m(node->left, i, result);
    search_m(node->right, i, result);
}

void itvtree::search_mi(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.y) return;

    if (node->key < i.y)
    {
        search_mi(node->right, i, result);
        return;
    }
    if (node->key > i.y)
    {
        search_mi(node->left, i, result);
        return;
    }

    result.push_back(node->data.itv);

    search_mi(node->left, i, result);
    search_mi(node->right, i, result);
}

void itvtree::search_e(RB_Node* node, Interval i, vector<Interval>& result)
{
    if (node == m_nullNode) return;
    if (node->data.maxvalue < i.x) return;

    if (node->key < i.x)
    {
        if (node->key == i.x && node->data.itv.y==i.y)
            result.push_back(node->data.itv);
        search_e(node->right, i, result);
        return;
    }
    if (node->key > i.x)
    {
        search_e(node->left, i, result);
        return;
    }

    if (node->data.itv.y==i.y)
        result.push_back(node->data.itv);

    search_e(node->left, i, result);
    search_e(node->right, i, result);
}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once

#include<vector>
//#include"point.h"

class rangetree
{
public:
    size_t keypos;
    rangetree* lchild;
    rangetree* rchild;
    rangetree* yroot;
    static int dim;
    static vector<Point>  data;
    vector<size_t> idx;

public:
    rangetree();
    rangetree(vector<Point>& indata);
    rangetree(size_t pos);
    rangetree(vector<size_t>& idx, int d);
    ~rangetree();


public:
    bool buildtree();
    bool build(vector<size_t>& idx);
    void sortdata(int d);
    void rangequery(Point from, Point to, vector<Point>& result);
    rangetree* find_split(Point& low, Point& high, int d);
    void intervalquery(Point from, Point to, vector<Point>& result, int d);
    void traversal_inorder( vector<Point>& result);
    void printtree();
    bool isleaf();



};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#include<algorithm>
#include<iostream>
//#include"rangetree.h"


using namespace std;

int rangetree::dim=1;
vector<Point>  rangetree::data;

rangetree::rangetree():lchild(NULL),rchild(NULL),yroot(NULL)
{
    vector<size_t> idx = sort_index(data,xless);
    size_t n = idx.size();
    keypos = idx[!(n % 2) ? n / 2 - 1 : (n - 1) / 2];
}

rangetree::rangetree(vector<Point>& indata) : lchild(NULL), rchild(NULL), yroot(NULL)
{
    data=indata;
    new(this) rangetree();
}

rangetree::rangetree(size_t pos) : keypos(pos), lchild(NULL), rchild(NULL), yroot(NULL)
{
}

rangetree::rangetree(vector<size_t>& idx, int di) : lchild(NULL), rchild(NULL), yroot(NULL)
{
    if (di==1 )
    {
        sort_index(data,idx,xless);
    }
    else if (di==2)
    {
        sort_index(data, idx, yless);
    }
    size_t n = idx.size();
    keypos=idx[!(n % 2) ? n / 2 - 1 : (n - 1) / 2];
}

rangetree::~rangetree()
{
    delete lchild;
    delete rchild;
    if(yroot!=this) delete yroot;
}

void rangetree::sortdata(int d)
{
    switch (d)
    {
        case 1:
            sort(data.begin(),data.end(),xless);
            break;
        case 2:
            sort(data.begin(),data.end(),yless);
            break;
        default:
            cerr<<"invalid parameter of function sort()."<<endl;
            exit(-1);
    }

}



bool rangetree::build(vector<size_t>& idx)
{

    size_t n=idx.size();
    if (n==0)
        return false;

    size_t pos = !(n % 2) ? n / 2 - 1 : (n - 1) / 2;
//	cout<<"current node:";
//	p->key.display();

    if(n==1)
    {
        this->lchild=NULL;
        this->rchild=NULL;
        this->yroot=this;
    }
    else
    {
        vector<size_t> left,right;
        left.assign(idx.begin(),idx.begin()+pos+1);
        right.assign(idx.begin()+pos+1,idx.end());
        this->lchild= new rangetree(left,dim);
        this->rchild= new rangetree(right,dim);

//		cout<<"\nbuilding left tree"<<endl;
        this->lchild->build(left);
//		cout<<"\nbuilding right tree"<<endl;
        this->rchild->build(right);

        // if in the first dimension, build y-tree.
        if (dim==1)
        {
            dim++;
            this->yroot= new rangetree(idx,dim);
//			cout<<"\nbuilding ytree"<<endl;
            this->yroot->build(idx);
            dim--;
        }
    }

    return true;
}

bool rangetree::buildtree()
{
    char a;
    vector<size_t> idx = sort_index(data, xless);
    build(idx);
    return true;
}

void rangetree::printtree()
{
    cout<<data[keypos]<<endl;
    cout<<"L";
    if (lchild!=NULL)	lchild->printtree();
    cout<<"R";
    if(rchild!=NULL)    rchild->printtree();


}

void  rangetree::rangequery(Point from, Point to, vector<Point>& result)
{
    result.clear();
    rangetree* split = find_split(from,to,1);
    if (split==NULL) return;

    if (split->isleaf())  // if split is leaf node, add it to the results
    {
        split->yroot->intervalquery(from,to,result,2);
        return;
    }

    //query point from
    rangetree*  s=split->lchild;
    if(from.x<=XMIN)
    {
        s->yroot->intervalquery(from,to, result,  2);
    }
    else
    {
        while( s!=NULL )
        {
            if( !xless(data[s->keypos],from) )
            {
                if(s->isleaf())     // leaf node
                {
                    s->yroot->intervalquery(from,to,result, 2);
                }
                else
                {
                    s->rchild->yroot->intervalquery(from,to,result, 2);
                }
                s=s->lchild;
            }
            else
            {
                s=s->rchild;
            }
        }
    }

    //query point to
    s=split->rchild;
    if (to.x>=XMAX)
    {
        s->yroot->intervalquery(from,to, result,  2);
    }
    else
    {
        while( s!=NULL )
        {
            if( !xless(to,data[s->keypos]) )
            {
                if(s->isleaf())  //leaf node
                {
                    s->yroot->intervalquery(from,to,result, 2);
                }
                else
                {
                    s->lchild->yroot->intervalquery(from,to,result, 2);
                }

                s=s->rchild;
            }
            else
            {
                s=s->lchild;
            }
        }
    }


}

rangetree* rangetree::find_split(Point& low, Point& high, int d)
{
    CompFun less = (d==1) ? xless : yless;
    rangetree* s=this;


    //  if low is greater than high, swap them
    if ( less(high,low))
    {
        return NULL;
    }

    // query
    while (s!=NULL)
    {
        if( less(data[s->keypos],low) )
        {
            //			cout<<"\nsplit on right tree."<<endl;
            s=s->rchild;
        }
        else if ( less(high,data[s->keypos]) )
        {
            //			cout<<"\nsplit on left tree."<<endl;
            s=s->lchild;
        }
        else
        {
            //			cout<<"\ncurrent split.";
            //			s->key.display();
            return s;
        }
    }
    return NULL;
}

void rangetree::intervalquery(Point from, Point to, vector<Point>& result, int d)
{
    rangetree* split = find_split(from,to,d);
    if (split==NULL) return;

    if (split->isleaf())  // if split is leaf node, add it to the results
    {
        split->traversal_inorder(result);
        return;
    }

    CompFun less;
    bool ismin,ismax;
    if(d==1)
    {
        less=xless;
        ismin = from.x<=XMIN;
        ismax = to.x>=XMAX;
    }
    else if(d==2)
    {
        less=yless;
        ismin = from.y<=YMIN;
        ismax = to.y>=YMAX;
    }

    //query point from
    rangetree*  s=split->lchild;
    if(ismin)
        s->traversal_inorder( result);
    else
    {
        while( s!=NULL )
        {
            if( !less(data[s->keypos],from) )
            {
                if(s->isleaf()) s->traversal_inorder(result);
                else s->rchild->traversal_inorder( result);
                s=s->lchild;
            }
            else
            {
                s=s->rchild;
            }
        }
    }

    //query point to
    s=split->rchild;
    if (ismax)
        s->traversal_inorder( result);
    else
    {
        while( s!=NULL )
        {
            if( !less(to,data[s->keypos]) )
            {
                if(s->isleaf())  s->traversal_inorder(result);
                else s->lchild->traversal_inorder( result);
                s=s->rchild;
            }
            else
            {
                s=s->lchild;
            }
        }
    }

}

void rangetree::traversal_inorder(vector<Point>& result)
{
    rangetree* root = this;
    if(root!=NULL)
    {
        if(root->isleaf()) result.push_back(data[root->keypos]);
        else
        {
            if(root->lchild!=NULL) root->lchild->traversal_inorder(result);
            if(root->rchild!=NULL) root->rchild->traversal_inorder(result);
        }
    }

}

bool rangetree::isleaf()
{
    return lchild == NULL && rchild == NULL;
}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once

#include<vector>
//#include"point.h"

class rangetree1d
{
public:
    size_t keypos;
    rangetree1d* lchild;
    rangetree1d* rchild;

    static vector<Point>  data;



public:
    rangetree1d();
    rangetree1d(const vector<Point>& indata);
    rangetree1d(size_t pos);
    rangetree1d(const vector<size_t>& idx);
    ~rangetree1d();


public:
    bool buildtree();
    bool build(vector<size_t>& idx);
    void sortdata(int d);
//	void rangequery(Point from, Point to, vector<Point>& result);
    template<typename Tree>
    static Tree* find_split(Tree* root, Point& low, Point& high, int d);
    void rangequery(Point from, Point to, vector<Point>& result, int d);
    void traversal_inorder(vector<Point>& result);
    void printtree();
    bool isleaf();
    unsigned long long size();


};

class rangetree2d
{
public:
    size_t keypos;
    rangetree2d* lchild;
    rangetree2d* rchild;
    rangetree1d* ytree;
    static vector<Point>  data;

public:
    rangetree2d();
    rangetree2d(const vector<Point>& indata);
    ~rangetree2d();

    bool buildtree();
    bool build(vector<size_t>& idx);
    void printtree();
    void rangequery(Point from, Point to, vector<Point>& result);
    bool isleaf();
    unsigned long long size();
};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#include<algorithm>
#include<iostream>
//#include"rangetree2d.h"


using namespace std;


vector<Point>  rangetree1d::data;
vector<Point>  rangetree2d::data;

rangetree1d::rangetree1d() :keypos(0), lchild(NULL), rchild(NULL)
{
}

rangetree1d::rangetree1d(const vector<Point>& indata) : lchild(NULL), rchild(NULL)
{
    data = indata;
}

rangetree1d::rangetree1d(size_t pos) : keypos(pos), lchild(NULL), rchild(NULL)
{
}

rangetree1d::rangetree1d(const vector<size_t>& idx) : lchild(NULL), rchild(NULL)
{
    size_t n = idx.size();
    keypos = idx[!(n % 2) ? n / 2 - 1 : (n - 1) / 2];
}

rangetree1d::~rangetree1d()
{
    delete lchild;
    delete rchild;
}

void rangetree1d::sortdata(int d)
{
    switch (d)
    {
        case 1:
            sort(data.begin(), data.end(), xless);
            break;
        case 2:
            sort(data.begin(), data.end(), yless);
            break;
        default:
            cerr << "invalid parameter of function sort()." << endl;
            exit(-1);
    }

}



bool rangetree1d::build(vector<size_t>& idx)
{
    size_t n = idx.size();
    if (n == 0)
        return false;

    size_t pos = !(n % 2) ? n / 2 - 1 : (n - 1) / 2;
    keypos = idx[pos];


    if (n == 1)
    {
        this->lchild = NULL;
        this->rchild = NULL;
    }
    else
    {
        vector<size_t> left, right;
        left.assign(idx.begin(), idx.begin() + pos + 1);
        right.assign(idx.begin() + pos + 1, idx.end());
        this->lchild = new rangetree1d();
        this->rchild = new rangetree1d();

        //		cout<<"\nbuilding left tree"<<endl;
        lchild->build(left);
        //		cout<<"\nbuilding right tree"<<endl;
        rchild->build(right);
    }


    return true;
}

bool rangetree1d::buildtree()
{
    vector<size_t> idx = sort_index(data, yless);
    build(idx);
    return true;
}

void rangetree1d::printtree()
{
    cout << data[keypos] << endl;
    cout << "L";
    if (lchild != NULL)	lchild->printtree();
    cout << "R";
    if (rchild != NULL)    rchild->printtree();


}


template<typename Tree>
Tree* rangetree1d::find_split(Tree* root, Point& low, Point& high, int d)
{
    CompFun less = (d == 1) ? xless : yless;
    Tree* s = root;
    //int h = 0; //height

    //  if low is greater than high, swap them
    if (less(high, low))
    {
        return NULL;
    }

    // query
    while (s != NULL)
    {
        if (less(data[s->keypos], low))
        {
            //			cout<<"\nsplit on right tree."<<endl;
            s = s->rchild;
        }
        else if (less(high, data[s->keypos]))
        {
            //			cout<<"\nsplit on left tree."<<endl;
            s = s->lchild;
        }
        else
        {
            //			cout<<"\ncurrent split.";
            //			s->key.display();
            return s;
        }

    }
    return NULL;
}

void rangetree1d::rangequery(Point from, Point to, vector<Point>& result, int d)
{
    rangetree1d* split = find_split(this,from, to, d);
    if (split == NULL) return;

    if (split->isleaf())  // if split is leaf node, add it to the results
    {
        split->traversal_inorder(result);
        return;
    }

    CompFun less;
    bool ismin, ismax;
    if (d == 1)
    {
        less = xless;
        ismin = from.x <= XMIN;
        ismax = to.x >= XMAX;
    }
    else if (d == 2)
    {
        less = yless;
        ismin = from.y <= YMIN;
        ismax = to.y >= YMAX;
    }

    //query point from
    rangetree1d*  s = split->lchild;
    if (ismin)
        s->traversal_inorder(result);
    else
    {
        while (s != NULL)
        {
            if (!less(data[s->keypos], from))
            {
                if (s->isleaf()) s->traversal_inorder(result);
                else s->rchild->traversal_inorder(result);
                s = s->lchild;
            }
            else
            {
                s = s->rchild;
            }
        }
    }

    //query point to
    s = split->rchild;
    if (ismax)
        s->traversal_inorder(result);
    else
    {
        while (s != NULL)
        {
            if (!less(to, data[s->keypos]))
            {
                if (s->isleaf())  s->traversal_inorder(result);
                else s->lchild->traversal_inorder(result);
                s = s->rchild;
            }
            else
            {
                s =s->lchild;
            }
        }
    }


}

void rangetree1d::traversal_inorder(vector<Point>& result)
{
    rangetree1d* root = this;
    if (root != NULL)
    {
        if (root->isleaf()) result.push_back(data[root->keypos]);
        else
        {
            if (root->lchild != NULL) root->lchild->traversal_inorder(result);
            if (root->rchild != NULL) root->rchild->traversal_inorder(result);
        }
    }
}

bool rangetree1d::isleaf()
{
    return lchild == NULL && rchild == NULL;
}


rangetree2d::rangetree2d() : ytree(NULL)
{
}

rangetree2d::rangetree2d(const vector<Point>& indata) : ytree(NULL)
{
    data = indata;
    rangetree1d::data = indata;
}

rangetree2d::~rangetree2d()
{
    delete lchild;
    delete rchild;
    delete ytree;
}

bool rangetree2d::build(vector<size_t>& idx)
{
    size_t n = idx.size();
    if (n == 0)
        return false;

    size_t pos = !(n % 2) ? n / 2 - 1 : (n - 1) / 2;
    keypos = idx[pos];


    if (n == 1)
    {
        this->lchild = NULL;
        this->rchild = NULL;
    }
    else
    {
        vector<size_t> left, right;
        left.assign(idx.begin(), idx.begin() + pos + 1);
        right.assign(idx.begin() + pos + 1, idx.end());
        this->lchild = new rangetree2d();
        this->rchild = new rangetree2d();

        //		cout<<"\nbuilding left tree"<<endl;
        lchild->build(left);
        //		cout<<"\nbuilding right tree"<<endl;
        rchild->build(right);
    }
    // build y-tree.

    this->ytree = new rangetree1d();
    sort_index(data, idx, yless);
    this->ytree->build(idx);



    return true;
}

bool rangetree2d::buildtree()
{
    vector<size_t> idx = sort_index(data, xless);
    build(idx);
    return true;
}

void  rangetree2d::rangequery(Point from, Point to, vector<Point>& result)
{
    result.clear();
    rangetree2d* split = rangetree1d::find_split(this, from, to, 1);
    if (split == NULL) return;

    if (split->isleaf())  // if split is leaf node, add it to the results
    {
        split->ytree->rangequery(from, to, result, 2);
        return;
    }

    //query point from
    rangetree2d*  s = split->lchild;
    if (from.x <= XMIN)
    {
        s->ytree->rangequery(from, to, result, 2);
    }
    else
    {
        while (s != NULL)
        {
            if (!xless(data[s->keypos], from))
            {
                if (s->isleaf())     // leaf node
                {
                    s->ytree->rangequery(from, to, result, 2);
                }
                else
                {
                    s->rchild->ytree->rangequery(from, to, result, 2);
                }
                s = (s->lchild);
            }
            else
            {
                s = (s->rchild);
            }
        }
    }

    //query point to
    s = (split->rchild);
    if (to.x >= XMAX)
    {
        s->ytree->rangequery(from, to, result, 2);
    }
    else
    {
        while (s != NULL)
        {
            if (!xless(to, data[s->keypos]))
            {
                if (s->isleaf())  //leaf node
                {
                    s->ytree->rangequery(from, to, result, 2);
                }
                else
                {
                    s->lchild->ytree->rangequery(from, to, result, 2);
                }

                s = s->rchild;
            }
            else
            {
                s = s->lchild;
            }
        }
    }

}

void rangetree2d::printtree()
{
    cout << data[keypos] << endl;
    cout << "L";
    if (lchild != NULL)	lchild->printtree();
    cout << "R";
    if (rchild != NULL)   rchild->printtree();
    cout << "Y";
    ytree->printtree();

}

bool rangetree2d::isleaf()
{
    return lchild == NULL && rchild == NULL;
}

unsigned long long  rangetree2d::size()
{
    unsigned long long r = sizeof(*this);
    if (lchild != NULL) r += lchild->size();
    if (rchild != NULL) r += rchild->size();
    if (ytree != NULL) r += ytree->size();
    return r;
}

unsigned long long  rangetree1d::size()
{
    unsigned long long r = sizeof(*this);
    if (lchild != NULL) r += lchild->size();
    if (rchild != NULL) r += rchild->size();
    return r;
}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once
#include<vector>
//#include "point.h"

class rangetreeFC
{
// constructor
public:
    rangetreeFC(void);
    rangetreeFC(vector<Point>& indata );
//destructor
public:
    ~rangetreeFC(void);
// member variable
public:
    Point key;
    vector<Point>  data;
    rangetreeFC* lchild;
    rangetreeFC* rchild;
    vector<size_t> lindex;   // data index in the left child data
    vector<size_t> rindex;   // data index in the righ child data
// member function
public:
    void sortdata(int d);
    size_t getsize();
    bool buildtree();
    void rangequery(Point from, Point to, vector<Point>& result);
    static rangetreeFC* find_split(Point& low, Point& high, rangetreeFC* node );
    void printtree();
    static void fcset(vector<Point>& A1, vector<Point>& A2, vector<size_t>& index,  CompFun less);   // set the index for fractional cascading
    static void intervalquery(vector<Point>& data,  Point from, Point to, size_t& lo, size_t& hi);  // interval query from the current node
    static size_t bsearch(Point P, vector<Point>& V);
    static void inserttoresult(rangetreeFC* datanode, size_t lo,size_t hi, vector<Point>& result);
    static void inserttoresult(rangetreeFC* datanode, size_t lo, Point to, vector<Point>& result);
    bool isleaf();  //whether this node is a leaf node
    static void indextransfer(vector<size_t>& index, size_t low, size_t high, size_t& newlow, size_t& newhigh);
};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#include<algorithm>
//#include "rangetreeFC.h"

rangetreeFC::rangetreeFC(void)
{
    lchild = NULL;
    rchild = NULL;
}

rangetreeFC::rangetreeFC(vector<Point>& indata )
{

    lchild = NULL;
    rchild = NULL;

    if (!issorted(indata,xless))
    {
        sort(indata.begin(),indata.end(),xless);
    }

    size_t n = indata.size();
    data=indata;
    key = data[!(n%2) ? (n/2-1) : (n-1)/2];
    lindex.resize(n+1,-1);
    rindex.resize(n+1,-1);  // an additional size_t to store the end, it would be the size of the subvector.
}



rangetreeFC::~rangetreeFC(void)
{

    delete lchild;

    delete rchild;
}

void rangetreeFC::sortdata(int d)  // d is the dimension
{
    switch (d)
    {
        case 1:
            sort(data.begin(),data.end(),xless);
            break;
        case 2:
            sort(data.begin(),data.end(),yless);
            break;
        default:
            cerr<<"invalid parameter of function sort()."<<endl;
            exit(-1);
    }
}

size_t rangetreeFC::getsize()
{
    return data.size();
}

bool rangetreeFC::buildtree()
{
    size_t n=getsize();
    if (n==0)
        return false;

//	cout<<"\ncurrent point:";
//	key.display();
//	cout<<endl;
    if(n==1)
    {
        lchild=NULL;
        rchild=NULL;
    }
    else
    {
        size_t pos= !(n%2) ? n/2-1 : (n-1)/2;
        vector<Point> left,right;
        left.assign(data.begin(),data.begin()+pos+1);
        right.assign(data.begin()+pos+1,data.end());

//		cout<<"\nbuilding left tree..."<<endl;
        lchild=new rangetreeFC(left);
        lchild->buildtree();

//		cout<<"\nbuilding right tree..."<<endl;
        rchild=new rangetreeFC(right);
        rchild->buildtree();

        sort(data.begin(),data.end(),yless);
        sort(left.begin(),left.end(),yless);
        sort(right.begin(),right.end(),yless);
        fcset(data,left,lindex,yless);
        fcset(data,right,rindex,yless);
    }

    return true;
}

void rangetreeFC::printtree()
{
    rangetreeFC* T=this;
    if(T!=NULL)
    {
        cout<<"\nkey:";
        T->key.display();
        cout<<"\ndata:";
        for_each(T->data.begin(),T->data.end(),display);
        cout<<"\nlindex:";
        for_each(T->lindex.begin(),T->lindex.end(),displayint);
        cout<<"\nrindex:";
        for_each(T->rindex.begin(),T->rindex.end(),displayint);
        cout<<"L";
        T->lchild->printtree();
        cout<<"R";
        T->rchild->printtree();
    }
}


//  A2  belong to A1
void rangetreeFC::fcset(vector<Point>& A1,vector<Point>& A2,vector<size_t>& index, CompFun less)
{
    size_t n1 =A1.size();
    size_t n2 =A2.size();
    size_t i=0,j=0;

    for(;j<n2;j++)
    {
        for(;i<n1;i++)
        {
            if( !less(A2[j],A1[i]) ) index[i]=j;
            else break;
        }
    }

}

void rangetreeFC::rangequery(Point from, Point to, vector<Point>& result)
{
    result.clear();
    rangetreeFC* split = find_split(from,to, this);
    if(split==NULL) return;

    size_t lowdex ; //the interval in split
//	intervalquery(split->data,from, to, lowdex, hidex);
    lowdex = bsearch(from, split->data );
    if(lowdex==-1 ) return;
    if(split->isleaf())
    {
        inserttoresult(split, lowdex ,to, result);
        return;
    }

    ////query point from
    rangetreeFC*  s=split->lchild;
    size_t low;  // the lowindex and highindex in subsets
//	indextransfer(split->lindex,lowdex,hidex,low,high);
    low=split->lindex[lowdex];

    if(low!=-1 )
    {
        if(from.x<=XMIN)
        {
            inserttoresult(s, low, to, result);
        }
        else
        {
            while( s!=NULL )
            {
                if( !xless(s->key,from) )
                {
                    if(s->lchild==NULL && s->rchild==NULL)
                        inserttoresult(s, low, to, result);
                    else
                    {
                        inserttoresult(s->rchild, s->rindex[low], to, result);
                    }

                    low=s->lindex[low];
                    if (low==-1) break;
                    s=s->lchild;
                }
                else
                {
                    low=s->rindex[low];
                    if (low==-1) break;
                    s=s->rchild;
                }
            }
        }
    }

    //query point to
    s=split->rchild;
//	indextransfer(split->rindex,lowdex,hidex,low,high);
    low=split->rindex[lowdex];
    if(low!=-1 )
    {
        if (to.x>=XMAX)
        {
            inserttoresult(s, low, to, result);
        }
        else
        {
            while( s!=NULL )
            {
                if( !xless(to,s->key) )
                {
                    if(s->lchild==NULL && s->rchild==NULL)
                    {
                        inserttoresult(s, low,to, result);
                    }
                    else
                    {
                        inserttoresult(s->lchild, s->lindex[low], to, result);

                    }

                    low=s->rindex[low];
                    if (low==-1) break;
                    s=s->rchild;
                }
                else
                {
                    low=s->lindex[low];
                    if (low==-1) break;
                    s=s->lchild;
                }
            }
        }
    }
}

rangetreeFC* rangetreeFC::find_split(Point& low, Point& high, rangetreeFC* node )
{
    //  if low is greater than high, return NULL
    if (xless(high, low) || yless(high, low))
    {
        return NULL;
    }

    // query
    rangetreeFC* s=node;
    while (s!=NULL)
    {
        if( xless(s->key,low) )
        {
            s=s->rchild;
        }
        else if ( xless(high,s->key) )
        {
            s=s->lchild;
        }
        else
        {
            return s;
        }
    }
    return NULL;
}

// interval query from the current node, lo and hi is the index
void rangetreeFC::intervalquery(vector<Point>& data, Point from, Point to, size_t& lo, size_t& hi)
{
    //  if low is greater than high, swap them
    if ( yless(to,from))
    {
        Point temp=from;
        from=to;
        to=temp;
    }

    lo = bsearch(from, data);
    hi = bsearch(to,data);


    //if (lo==-1)   // the from position exceeds the end
    //{
    //	hi=-1;
    //	return;
    //}
    //size_t n=data.size();
    //size_t i=lo;
    //for(;i<n && !yless(to,data[i]);i++);

    //hi=i; // if hi<lo, the to position prior to the begin.


}

// return the first position where the value is not less than the given point P.
size_t rangetreeFC::bsearch(Point P, vector<Point>& V)
{
    // binary search
    size_t n = V.size();
    size_t l=0;
    size_t h=n-1;
    size_t m=h,i;
    while(int(l)<=int(h)){
        m=(l+h)/2;
        if( V[m].y == P.y)
        {
            for (i=m;int(i)>=0;i--)    //  in case of some equal elements
            {
                if(V[i].y!=P.y) break;
            }
            return i+1;
        }
        if( yless(P,V[m])) h=m-1;
        else l=m+1;
    }
    if(h == m-1) return m;
    else return m+1<n ? m+1 : -1;    // if the position exceeds, return -1.
}

void rangetreeFC::inserttoresult(rangetreeFC* datanode, size_t lo, Point to, vector<Point>& result)
{

    if(datanode==NULL) return;
    if(lo==-1) return;

    vector<Point>& V=datanode->data;
    size_t i, n=V.size();


    //if (hi==-1)
    //{
    //	result.insert(result.end(),V.begin()+lo, V.end());
    //	return;
    //}
    //if(to.y>=V[hi].y)
    //{
    //size_t i=hi;
    //for(; i<n && V[i].y==V[hi].y;i++);
    //hi=i;
    //}
    //result.insert(result.end(),V.begin()+lo, V.begin()+hi);

//	if (hi==-1)  hi=n;


    //for(i=lo;i<hi;i++)
    //{
    //	result.push_back(V[i]);
    //}

    for(i=lo;i<n && !yless(to,V[i]);i++)
    {
        result.push_back(V[i]);
    }


}

bool rangetreeFC::isleaf()
{
    if(lchild==NULL && rchild==NULL) return true;

    return false;
}

void rangetreeFC::indextransfer(vector<size_t>& index, size_t low, size_t high, size_t& newlow, size_t& newhigh)
{
    if(low==-1 )
    {
        newlow=-1;
        return;
    }

    newlow=index[low];
    newhigh= (high==-1) ? -1: index[high];


}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#pragma once
#include<vector>
#include<deque>
//#include "point.h"

class rtfc_eqkey
{
    // constructor
public:
    rtfc_eqkey(void);
    rtfc_eqkey(vector<size_t>& index);
    rtfc_eqkey(vector<Point>& indata);
    //destructor
public:
    ~rtfc_eqkey(void);
    // member variable
public:
    size_t keypos;

    rtfc_eqkey* lchild;
    rtfc_eqkey* rchild;
    vector<size_t> lindex;   // data index in the left child data
    vector<size_t> rindex;   // data index in the righ child data
    vector<size_t> dataindex;   //the difference to rangetreeFC,  y order index
    vector<size_t> eqidx;  // index to the points that have equal begin value.

    static	vector<Point>  data;  //
    // member function
public:
    //	void sortdata(int d);
    //	size_t getsize();
    bool buildtree();
    void rangequery(Point from, Point to, vector<Point>& result);
    rtfc_eqkey* find_split(Point& low, Point& high);
    void printtree();
    static void fcset(vector<size_t>& A1, vector<size_t>& A2, vector<size_t>& index, CompFun less);   // set the index for fractional cascading
    static void intervalquery(vector<Point>& data, Point from, Point to, size_t& lo, size_t& hi);  // interval query from the current node
    static size_t bsearch(Point& P, vector<size_t>& V);
    static void inserttoresult(rtfc_eqkey* datanode, size_t lo, Point& to, vector<Point>& result);
    bool isleaf();  //whether this node is a leaf node
    static void indextransfer(vector<size_t>& index, size_t low, size_t high, size_t& newlow, size_t& newhigh);
    unsigned long long size();
    //	vector<Point> indextodata(vector<size_t> index);

};

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#include<algorithm>
//#include "rtfc_eqkey.h"

vector<Point>  rtfc_eqkey::data;

rtfc_eqkey::rtfc_eqkey(void)
{
    size_t n = data.size();

    //	for (size_t i = 0; i < n; i++) dataindex[i] = i;
    //	iota(dataindex.begin(), dataindex.end(), 0);
    dataindex = sort_index(data, xless);
    size_t mid = !(n % 2) ? (n / 2 - 1) : (n - 1) / 2;
    keypos = dataindex[mid];
    eqidx.push_back(keypos);
    for (int i = mid + 1; i < n && data[keypos].x == data[dataindex[i]].x; i++)
    {
        eqidx.push_back(dataindex[i]);
    }
    for (int i = mid - 1; i >= 0 && data[keypos].x == data[dataindex[i]].x; i--)
    {
        eqidx.push_back(dataindex[i]);
    }
    sort_index(data, eqidx, yless);
    lindex.resize(n + 1, -1);
    rindex.resize(n + 1, -1);  // an additional size_t to store the end, it would be the size of the subvector.
    lchild = NULL;
    rchild = NULL;
}

rtfc_eqkey::rtfc_eqkey(vector<size_t>& index)
{
    size_t n = index.size();

    dataindex = index;
    size_t mid = !(n % 2) ? (n / 2 - 1) : (n - 1) / 2;
    keypos = dataindex[mid];
    eqidx.push_back(keypos);
    for (int i = mid + 1; i < n && data[keypos].x == data[dataindex[i]].x; i++)
    {
        eqidx.push_back(dataindex[i]);
    }
    for (int i = mid - 1; i >= 0 && data[keypos].x == data[dataindex[i]].x; i--)
    {
        eqidx.push_back(dataindex[i]);
    }
    sort_index(data, eqidx, yless);
    lindex.resize(n + 1, -1);
    rindex.resize(n + 1, -1);  // an additional size_t to store the end, it would be the size of the subvector.
    lchild = NULL;
    rchild = NULL;
}

rtfc_eqkey::rtfc_eqkey(vector<Point>& indata)
{
    data = indata;
    new(this) rtfc_eqkey();
}



rtfc_eqkey::~rtfc_eqkey(void)
{
    delete lchild;

    delete rchild;

}



bool rtfc_eqkey::buildtree()
{
    size_t n = dataindex.size();
    if (n == 0)
        return false;

    //	cout<<"\ncurrent point:";
    //	key.display();
    //	cout<<endl;
    if (n == 1)
    {
        lchild = NULL;
        rchild = NULL;
    }
    else
    {
        size_t pos = !(n % 2) ? n / 2 - 1 : (n - 1) / 2;
        vector<size_t> left, right;
        left.assign(dataindex.begin(), dataindex.begin() + pos + 1);
        right.assign(dataindex.begin() + pos + 1, dataindex.end());

        //		cout<<"\nbuilding left tree..."<<endl;
        lchild = new rtfc_eqkey(left);
        lchild->buildtree();

        //		cout<<"\nbuilding right tree..."<<endl;
        rchild = new rtfc_eqkey(right);
        rchild->buildtree();

        sort_index(data, dataindex);
        //sort_index(data, left);
        //sort_index(data, right);

        fcset(dataindex, lchild->dataindex, lindex, yless);
        fcset(dataindex, rchild->dataindex, rindex, yless);
    }

    return true;
}

void rtfc_eqkey::printtree()
{
    rtfc_eqkey* T = this;
    if (T != NULL)
    {
        cout << "\nkey:";
        data[T->keypos].display();
        cout << "\ndata:";
        for_each(T->dataindex.begin(), T->dataindex.end(), displayint);
        cout << "\nlindex:";
        for_each(T->lindex.begin(), T->lindex.end(), displayint);
        cout << "\nrindex:";
        for_each(T->rindex.begin(), T->rindex.end(), displayint);
        cout << "L";
        T->lchild->printtree();
        cout << "R";
        T->rchild->printtree();
    }
}


//  A2  belong to A1
void rtfc_eqkey::fcset(vector<size_t>& A1, vector<size_t>& A2, vector<size_t>& index, CompFun less)
{
    size_t n1 = A1.size();
    size_t n2 = A2.size();
    size_t i = 0, j = 0;

    for (; j<n2; j++)
    {
        for (; i<n1; i++)
        {
            if (!less(data[A2[j]], data[A1[i]])) index[i] = j;
            else break;
        }
    }

}

void rtfc_eqkey::rangequery(Point from, Point to, vector<Point>& result)
{
    result.clear();
    rtfc_eqkey* split = find_split(from, to);
    if (split == NULL) return;

    size_t lowdex; //the interval in split
    if (from.x == to.x)
    {
        lowdex = bsearch(from, split->eqidx);
        for (auto i = lowdex; i< split->eqidx.size() && !yless(to, data[split->eqidx[i]]); i++)
        {
            result.push_back(data[split->eqidx[i]]);
        }
        return;
    }

    lowdex = bsearch(from, split->dataindex);
    if (lowdex == -1) return;
    if (split->isleaf())
    {
        inserttoresult(split, lowdex, to, result);
        return;
    }

    //////query point from
    rtfc_eqkey*  s = split->lchild;
    size_t low;  // the lowindex and highindex in subsets
    //	indextransfer(split->lindex,lowdex,hidex,low,high);
    low = split->lindex[lowdex];

    if (low != -1)
    {
        if (from.x <= XMIN)
        {
            inserttoresult(s, low, to, result);
        }
        else
        {
            while (s != NULL)
            {
                if (!xless(data[s->keypos], from))
                {
                    if (s->lchild == NULL && s->rchild == NULL)
                        inserttoresult(s, low, to, result);
                    else
                    {
                        inserttoresult(s->rchild, s->rindex[low], to, result);
                    }

                    low = s->lindex[low];
                    if (low == -1) break;
                    s = s->lchild;
                }
                else
                {
                    low = s->rindex[low];
                    if (low == -1) break;
                    s = s->rchild;
                }
            }
        }
    }

    //query point to
    s = split->rchild;
    //	indextransfer(split->rindex,lowdex,hidex,low,high);
    low = split->rindex[lowdex];
    if (low != -1)
    {
        if (to.x >= XMAX)
        {
            inserttoresult(s, low, to, result);
        }
        else
        {
            while (s != NULL)
            {
                if (!xless(to, data[s->keypos]))
                {
                    if (s->lchild == NULL && s->rchild == NULL)
                    {
                        inserttoresult(s, low, to, result);
                    }
                    else
                    {
                        inserttoresult(s->lchild, s->lindex[low], to, result);

                    }

                    low = s->rindex[low];
                    if (low == -1) break;
                    s = s->rchild;
                }
                else
                {
                    low = s->lindex[low];
                    if (low == -1) break;
                    s = s->lchild;
                }
            }
        }
    }
}

rtfc_eqkey* rtfc_eqkey::find_split(Point& low, Point& high)
{
    //  if low is greater than high, return
    if (xless(high, low) || yless(high, low))
    {
        return NULL;
    }


    // query
    rtfc_eqkey* s = this;
    while (s != NULL)
    {
        if (xless(data[s->keypos], low))
        {
            s = s->rchild;
        }
        else if (xless(high, data[s->keypos]))
        {
            s = s->lchild;
        }
        else
        {
            return s;
        }
    }

    return NULL;
}

// interval query from the current node, lo and hi is the index
void rtfc_eqkey::intervalquery(vector<Point>& data, Point from, Point to, size_t& lo, size_t& hi)
{
    //  if low is greater than high, swap them
    if (yless(to, from))
    {
        Point temp = from;
        from = to;
        to = temp;
    }

    //	lo = bsearch(from, data);
    //	hi = bsearch(to, data);


    //if (lo==-1)   // the from position exceeds the end
    //{
    //	hi=-1;
    //	return;
    //}
    //size_t n=data.size();
    //size_t i=lo;
    //for(;i<n && !yless(to,data[i]);i++);

    //hi=i; // if hi<lo, the to position prior to the begin.


}

// return the first position where the value is not less than the given point P.
size_t rtfc_eqkey::bsearch(Point& P, vector<size_t>& V)
{
    // binary search
    size_t n = V.size();
    size_t l = 0;
    size_t h = n - 1;
    size_t m = h;
    while (int(l) <= int(h)) {
        /*	Point tl=data[V[l]];
        Point th = data[V[h]];

        if (yless(P, tl)) return l;
        if (yless(th, P))  return h + 1;
        if (tl.y == th.y) return l;*/

        //	m= l+ (P.y- tl.y)*(h-l) /(th.y- tl.y);
        m = (l + h) / 2;
        //	Point tm = data[V[m]];

        if (data[V[m]].y == P.y)
        {
            int i;
            for (i = m; i >= 0; i--)    //  in case of some equal elements
            {
                if (data[V[i]].y != P.y) break;
            }
            return i + 1;
        }
        if (P.y < data[V[m]].y) h = m - 1;
        else l = m + 1;
    }
    if (h == m - 1) return m;
    else return m + 1<n ? m + 1 : -1;    // if the position exceeds, return -1;
}

void rtfc_eqkey::inserttoresult(rtfc_eqkey* datanode, size_t lo, Point& to, vector<Point>& result)
{

    if (datanode == NULL) return;
    if (lo == -1) return;

    vector<size_t>& V = datanode->dataindex;
    size_t i, n = V.size();


    //if (hi==-1)
    //{
    //	result.insert(result.end(),V.begin()+lo, V.end());
    //	return;
    //}
    //if(to.y>=V[hi].y)
    //{
    //size_t i=hi;
    //for(; i<n && V[i].y==V[hi].y;i++);
    //hi=i;
    //}
    //result.insert(result.end(),V.begin()+lo, V.begin()+hi);

    //	if (hi==-1)  hi=n;


    //for(i=lo;i<hi;i++)
    //{
    //	result.push_back(V[i]);
    //}

    for (i = lo; i<n && !yless(to, data[V[i]]); i++)
    {
        result.push_back(data[V[i]]);
    }


}

bool rtfc_eqkey::isleaf()
{
    if (lchild == NULL && rchild == NULL) return true;

    return false;
}

void rtfc_eqkey::indextransfer(vector<size_t>& index, size_t low, size_t high, size_t& newlow, size_t& newhigh)
{
    if (low == -1)
    {
        newlow = -1;
        return;
    }

    newlow = index[low];
    newhigh = (high == -1) ? -1 : index[high];


}

unsigned long long  rtfc_eqkey::size()
{
    unsigned long long r = sizeof(*this);
    if (lchild != NULL) r += lchild->size();
    if (rchild != NULL) r += rchild->size();
    r += (lindex.capacity() + rindex.capacity() + dataindex.capacity()+eqidx.capacity()) * sizeof(size_t);
    return r;
}

/***************************************/
/* author: Chengsheng Mao	           */
/* version: 1.2	                       */
/***************************************/

#include<iostream>
#include<sstream>
#include <fstream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<time.h>
#include<sys/time.h>
#include<iomanip>
//#include<windows.h>

/*#include"point.h"
#include"rangetree.h"
#include"rangetreeFC.h"
#include"interval.h"
#include"intervaltree.h"
#include"indexrtFC.h"
#include"rangetree2d.h"
#include"itvtree.h"
#include"rtfc_eqkey.h"*/


using namespace std;

#define OPN 11

void queryproc(string datafile, vector<string>& queryfile);

int main(int argc, char** argv)
{
//    string filename = "./testdata/1.exons";
//    string queryfile = "./testdata/1.rnaseqs";

    string filename = argv[1];
    vector<string> queryfile;
    for(auto i=2;i<argc;i++)
        queryfile.push_back(argv[i]);

    for_each(queryfile.begin(),queryfile.end(),[](string s){cout<<s<<endl;});


    queryproc(filename, queryfile);

    return 0;


}

// query the intervals in queryfile from the intervals in datafile
void queryproc(string datafile, vector<string>& queryfile)
{
    vector<Point> origin;
    vector<vector<Point>> querydata(queryfile.size());
    vector<string> outfile(queryfile.size());
    vector<ofstream> outfs(queryfile.size());
    vector<string> op= { "o","oi","d","di","si","s","f","fi","m","mi","e","p","pi" };

    origin = readfile(datafile);
    for(auto i=0;i<queryfile.size();i++)
    {
        querydata[i] = readfile(queryfile[i]);
//        querydata[i].erase(querydata[i].begin(),querydata[i].begin()+100000);
        string outname=queryfile[i]+".res";
        outfs[i].open(outname.data());
        outfs[i]<<"#number of original data:"<<origin.size()<<endl;
        outfs[i]<<"#number of query data:"<<querydata[i].size()<<endl;
    }

    timeval  c1, c2;


/*************rangetreeFC****************/
    {
        indexrtFC Tfc(origin);
        cout<<"\nBuilding indexrtFC for "<<datafile<<"..."<<endl;  //for rangetree FC
        gettimeofday(&c1,NULL);
        Tfc.buildtree();   //build rangetreeFC
        gettimeofday(&c2,NULL);
        unsigned long bt=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);

        for(auto ifl=0;ifl<queryfile.size();ifl++)
        {
            outfs[ifl]<<"RTFC build time:"<<bt<<endl;
            size_t q_size=querydata[ifl].size();
            for(int j=0;j<OPN;j++)
            {
                unsigned long t=0;
                unsigned long n=0;
                vector<Point> result;
                cout<<op[j]<<" query for"<<queryfile[ifl]<<"..."<<endl;
                gettimeofday(&c1,NULL);
                for(int i=0;i<q_size;i++)
                {
                    Point  from, to;
                    Interval(querydata[ifl][i]).transform(op[j],from,to);
                    Tfc.rangequery(from,to,result);
                    n+=result.size();
                }
                gettimeofday(&c2,NULL);
                t=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);
                outfs[ifl]<<t<<','<<n<<endl;
            }
            outfs[ifl]<<endl;
        }
    }

/*************rtfc_eqkey****************/
/*{
	rtfc_eqkey Tfc(origin);
	cout<<"\nBuilding rtfc_eqkey for "<<datafile<<"..."<<endl;  //for rangetree FC
	gettimeofday(&c1,NULL);
	Tfc.buildtree();   //build rangetreeFC
	gettimeofday(&c2,NULL);
	unsigned long bt=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);

    for(auto ifl=0;ifl<queryfile.size();ifl++)
    {
        outfs[ifl]<<"rtfc_eqkey build time:"<<bt<<endl;
        size_t q_size=querydata[ifl].size();
        for(int j=0;j<OPN;j++)
        {
            unsigned long t=0;
            unsigned long n=0;
            vector<Point> result;
            cout<<op[j]<<" query for"<<queryfile[ifl]<<"..."<<endl;
            gettimeofday(&c1,NULL);
            for(int i=0;i<q_size;i++)
            {
                Point  from, to;
                Interval(querydata[ifl][i]).transform(op[j],from,to);
                Tfc.rangequery(from,to,result);
                n+=result.size();
            }
            gettimeofday(&c2,NULL);
            t=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);
            outfs[ifl]<<t<<','<<n<<endl;
        }
        outfs[ifl]<<endl;
    }
}
*/

/*************rangetree**********/
    {
        rangetree2d T(origin);
        cout<<"\nBuilding rangetree for "<<datafile<<"..."<<endl;  //for rangetree
        gettimeofday(&c1,NULL);
        T.buildtree();   //build rangetree
        gettimeofday(&c2,NULL);
        unsigned long bt=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);

        for(auto ifl=0;ifl<queryfile.size();ifl++)
        {
            outfs[ifl]<<"2D-RT build time:"<<bt<<endl;
            size_t q_size=querydata[ifl].size();
            for(int j=0;j<OPN;j++)
            {
                unsigned long t=0;
                unsigned long n=0;
                vector<Point> result;
                cout<<op[j]<<" query for"<<queryfile[ifl]<<"..."<<endl;
                gettimeofday(&c1,NULL);
                for(int i=0;i<q_size;i++)
                {
                    Point  from, to;
                    Interval(querydata[ifl][i]).transform(op[j],from,to);
                    T.rangequery(from,to,result);
                    n+=result.size();
                }
                gettimeofday(&c2,NULL);
                t=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);
                outfs[ifl]<<t<<','<<n<<endl;
            }
            outfs[ifl]<<endl;
        }
    }

    /*************itvtree**********/
    {
        itvtree iT;
        cout<<"\nBuilding itvtree for "<<datafile<<"..."<<endl;  //for rangetree FC
        gettimeofday(&c1,NULL);
        iT.buildtree(origin);    //build
        gettimeofday(&c2,NULL);
        unsigned long bt=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);

        typedef void (itvtree::*psearch)(itvtree::RB_Node* node, Interval i, \
                                          vector<Interval>& result) ;
        psearch search[]={&itvtree::search_o,&itvtree::search_oi, \
                        &itvtree::search_d,&itvtree::search_di, \
                        &itvtree::search_si,&itvtree::search_s, \
                        &itvtree::search_f,&itvtree::search_fi, \
                        &itvtree::search_m,&itvtree::search_mi, \
                        &itvtree::search_e,&itvtree::search_p,&itvtree::search_pi};

        for(auto ifl=0;ifl<queryfile.size();ifl++)
        {
            outfs[ifl]<<"IT build time:"<<bt<<endl;
            size_t q_size=querydata[ifl].size();
            for(int j=0;j<OPN;j++)
            {
                unsigned long t=0;
                unsigned long n=0;
                vector<Interval> result(0);
                cout<<op[j]<<" query for"<<queryfile[ifl]<<"..."<<endl;
                gettimeofday(&c1,NULL);
                for(int i=0;i<q_size;i++)
                {
                    result.clear();
                    Interval I(querydata[ifl][i]);
                    (iT.*search[j])(iT.m_root, I, result);

                    n+=result.size();
                }
                gettimeofday(&c2,NULL);
                t=1000000*(c2.tv_sec-c1.tv_sec)+(c2.tv_usec-c1.tv_usec);
                outfs[ifl]<<t<<','<<n<<endl;
            }
            outfs[ifl]<<endl;
        }
    }

    for(auto i=0;i<outfs.size();i++)
        outfs[i].close();

}