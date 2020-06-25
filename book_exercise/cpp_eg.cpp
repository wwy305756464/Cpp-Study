// 值传递
void warp(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 5, y = 10;
	cout << "x=" << x << "y=" << y << endl;
	swap(x, y);
	cout << "x=" << x << "y=" << y << endl;
	return 0
}

// 引用传递
void warp(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 5, y = 10;
	cout << "x=" << x << "y=" << y << endl;
	swap(x, y);
	cout << "x=" << x << "y=" << y << endl;
	return 0
}


class 类名称
{
public:
	外部接口
private:
	私有成员
protected:
	保护型成员
};


#include <iostream>
using namespace std;

class CExample {
private:
    int a;
public:
    //构造函数
    CExample(int b)
    { a = b;}
    
    //拷贝构造函数
    CExample(const CExample& C)
    { 
        a = C.a;
    }

    //一般函数
    void Show ()
    {
        cout<<a<<endl;
    }
};

int main()
{
    CExample A(100);
    CExample B = A; // CExample B(A); 也是一样的
     B.Show ();
    return 0;
} 







class CExample 
{
private:
 int a;

public:
 //构造函数
 CExample(int b)
 { 
  a = b;
  cout<<"creat: "<<a<<endl;
 }

 //拷贝构造
 CExample(const CExample& C)
 {
  a = C.a;
  cout<<"copy"<<endl;
 }
 
 //析构函数
 ~CExample()
 {
  cout<< "delete: "<<a<<endl;
 }

     void Show ()
 {
         cout<<a<<endl;
     }
};

//全局函数，传入的是对象
void g_Fun(CExample C)
{
 cout<<"test"<<endl;
}

int main()
{
 CExample test(1);
 //传入对象
 g_Fun(test);

 return 0;
}




\\ 


class point {
public:
	point (int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
	point (point &p);
	int getX() { return x; }
	int getY() { return y; }
private:
	int x, y;
};

point::point(point &p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of point" << endl;
}

class Line {
public:
	Line(point xp1, point xp2);
	Line(Line &l);
	double getLen() {return len;}
private:
	point p1, p2;
	double len;
};


Line::Line(point xp1, point xp2) : p1(xp1), p2(xp2) {
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x*x + y*y);
}

Line::Line(Line &l) : p1(l.p1), p2(l.p2) {
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}

int main() {
	point myp1(1,1), myp2(4,5);
	Line line(myp1, myp2);
	Line line2(line)
	cout << "The length of the line is: ";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is: ";
	cout << line2.getLen() << endl;
	return 0;
}

int a, b
const int *p1 = &a;
a = 300;
*p1 = 56;    // error
p1 = &b;

int a, b
int * const p2 = &a;
a = 500;
*p2 = 400;
p2 = &b;     // error

int a, b
const int * const p3 = &a;
a = 5000
*p3 = 600;   // error
p3 = &b;     // error




int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i=0; i < 10; ++i){
		cout << a[i] << endl;
	}
	return 0;
}

int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i=0; i<10; ++i) {
		cout * (a+i) << endl;
	}
	return 0;
}


int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int *p = a; p < (a+10); ++p) {
		cout << *p << endl;
	}
	return 0;
}




void printStuff(float) {
	cout << "This is the print stuff function" << endl;
}

void printMessage(float data) {
	cout << "The data to be listed is" << data << endl;
}

const float PI = 3.1415926;
const float TWO_PI = PI * 2.0f;

int main() {
	void (* functionPointer) (float); // 定义了一个叫做functionPointer的函数指针
									  // 有float形参，没有返回值
	printStuff(PI);  // >> this is the print stuff function
	functionPointer = printStuff;  // 函数指针指向printStuff，有点像funtionPointer是别名
	functionPointer(PI);	// 调用函数指针，>> this is the print stuff function
	functionPointer = printMessage;  // 函数指针指向printMessage
	functionPointer(TWO_PI);  // 调用函数指针 >> The data to be listed is 6.28318
	functionPointer(13.0);  // 调用函数指针 >> The data to be listed is 13
	return 0;
}




class B {...};
class D: public B {...};
B b1;
B *pb1;
D d1;

b1 = d1;
B &rb = d1;
pb1 = &d1;




@login_required
def contract_preview(request, profile_uuid):
    if request.method == 'GET':
        try:
            profile = InfluencerProfile.objects.get(profile_uuid=profile_uuid)
        except ObjectDoesNotExist:
            profile = AdvertiserProfile.objects.get(profile_uuid=profile_uuid)

        advertiser_profile = AdvertiserProfile.objects.get(user=request.user)
        context = {
            'other_profile': profile,
            'other_social_profile': SocialProfile.objects.filter(owner=profile)[0],
            'other_social_posts': Post.objects.filter(owner=profile)[0].data,
            'campaigns': Campaign.objects.filter(advertiser=advertiser_profile)
        }
        rendered_html = render_to_string(
            'explore_modals/contract_preview_modal.html',
            context=context,
            request=request
        )

        return JsonResponse({'success': 'true', 'html_form': rendered_html})
    else:
        return JsonResponse({"success": 'false'})



class ProfileView(GenericDashboardView):
    template_name = 'profile.html'

    def get_context_data(self, request, *args, **kwargs):
        context = super(ProfileView, self).get_context_data(request, *args, **kwargs)

        try:
            context['other_profile'] = InfluencerProfile.objects.get(profile_uuid=kwargs['profile_uuid'])
        except ObjectDoesNotExist:
            context['other_profile'] = AdvertiserProfile.objects.get(profile_uuid=kwargs['profile_uuid'])

        if context['other_profile'] and context['other_profile'].user.is_influencer and context['other_profile'].is_social_verified:
            context['other_social_profile'] = SocialProfile.objects.filter(owner=context['other_profile'])[0]
            context['other_social_posts'] = Post.objects.filter(owner=context['other_profile'])[0].data

        return context










