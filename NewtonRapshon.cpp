#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
float F(float x,float y){
    return (pow(x,3)-3*x*y*y-3*x+52);
}
float G(float x,float y){
    return (3*x*x*y-pow(y,3)-3*y);
}
float Fx(float x, float y){
    return (3*x*x-3*y*y-3);
}
float Fy(float x,float y){
    return (-6*x*y);
}
float Gx(float x,float y){
   return (6*x*y);
}
float Gy(float x,float y){
    return (3*x*x-3*y*y-3);
}

int main(){
    cout<<"Give the value of X0 => \n";
    float x[5];cin>>x[0];
    cout<<"Give the value of Y0 => \n";
    float y[5];cin>>y[0];
    cout<<"Number of iteraton => \n";
    int n;cin>>n;
    float f[5],g[5];
    float fx[5],fy[5];
    float gx[5],gy[5];
   for(int i=0;i<n;i++){
       
        f[i]=F(x[i],y[i]);g[i]=G(x[i],y[i]);
        fx[i]=Fx(x[i],y[i]);fy[i]=Fy(x[i],y[i]);
        gx[i]=Gx(x[i],y[i]);gy[i]=Gy(x[i],y[i]);
        float D[5],Dx[5],Dy[5];
        D[i]=(fx[i]*gy[i])-(fy[i]*gx[i]);
        Dx[i]=(f[i]*gy[i])-(fy[i]*g[i]);
        Dy[i]=(fx[i]*g[i])-(f[i]*gx[i]);
        float h[5],k[5];
        h[i]=(-1)*(Dx[i]/D[i]);
        k[i]=(-1)*(Dy[i]/D[i]);
        x[i+1]=x[i]+h[i];y[i+1]=y[i]+k[i];

        cout<<"f["<<i<<"] = "<<f[i];cout<<"\t g["<<i<<"] = "<<g[i]<<endl;
        cout<<"fx["<<i<<"] = "<<fx[i];cout<<"\t fy["<<i<<"] = "<<fy[i]<<endl;
        cout<<"gx["<<i<<"] = "<<gx[i];cout<<"\t gy["<<i<<"] = "<<gy[i]<<endl;
        cout<<"D["<<i<<"] = "<<D[i];cout<<"\t Dx["<<i<<"] = "<<Dx[i];cout<<"\t Dy["<<i<<"] = "<<Dy[i]<<endl;
        cout<<"h["<<i<<"] = "<<h[i];cout<<"\t k["<<i<<"] = "<<k[i]<<endl;
        cout<<"x["<<i+1<<"] = "<<x[i+1];cout<<"\t y["<<i+1<<"] = "<<y[i+1]<<endl;
        cout<<endl;cout<<endl;

   }
   
    
    cout<<"value of x is => "<<fixed<<setprecision(3)<<x[n]<<endl;
    cout<<"value of y is => "<<fixed<<setprecision(3)<<y[n]<<endl;


    return 0;
}