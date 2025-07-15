#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main() {
    // 1. 创建矩阵的几种方式
    
    // 动态大小矩阵（运行时确定大小）
    MatrixXd mat1(3, 4);  // 3行4列的double矩阵
    mat1 << 1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12;
    
    // 固定大小矩阵（编译时确定大小）
    Matrix3d mat2;  // 3x3的double矩阵
    mat2 << 1, 0, 0,
            0, 1, 0,
            0, 0, 1;  // 单位矩阵
    
    // 向量
    VectorXd vec(3);  // 3维动态向量
    vec << 1, 2, 3;
    
    Vector3d fixed_vec(1, 2, 3);  // 3维固定向量
    
    // 2. 常用操作
    
    // 访问元素
    std::cout << "mat1(0,1) = " << mat1(0, 1) << std::endl;  // 第0行第1列
    
    // 设置值
    mat1(2, 3) = 100;
    
    // 获取矩阵信息
    std::cout << "矩阵大小: " << mat1.rows() << "x" << mat1.cols() << std::endl;
    std::cout << "总元素数: " << mat1.size() << std::endl;
    
    // 3. 矩阵运算
    
    MatrixXd A(2, 2);
    MatrixXd B(2, 2);
    A << 1, 2,
         3, 4;
    B << 5, 6,
         7, 8;
    
    // 矩阵加法
    MatrixXd C = A + B;
    
    // 矩阵乘法
    MatrixXd D = A * B;
    
    // 转置
    MatrixXd At = A.transpose();
    
    // 逆矩阵
    MatrixXd Ainv = A.inverse();
    
    // 4. 多项式系数矩阵的典型用法
    
    // 假设有3段多项式，每段是3次多项式（4个系数：a0 + a1*t + a2*t^2 + a3*t^3）
    MatrixXd poly_coeff(3, 4);  // 3行4列
    poly_coeff << 1.0, 2.0, 0.5, 0.1,   // 第1段: 1.0 + 2.0*t + 0.5*t^2 + 0.1*t^3
                  0.5, 1.5, -0.2, 0.05,  // 第2段
                  2.0, 0.8, 0.3, -0.02;  // 第3段
    
    // 计算第1段多项式在 t=1.5 时的值
    double t = 1.5;
    double value = poly_coeff(0, 0) + 
                   poly_coeff(0, 1) * t + 
                   poly_coeff(0, 2) * t * t + 
                   poly_coeff(0, 3) * t * t * t;
    
    std::cout << "多项式值: " << value << std::endl;
    
    // 5. 实用的初始化方法
    
    // 零矩阵
    MatrixXd zeros = MatrixXd::Zero(3, 3);
    
    // 单位矩阵
    MatrixXd identity = MatrixXd::Identity(3, 3);
    
    // 常数矩阵
    MatrixXd ones = MatrixXd::Ones(2, 3);
    
    // 随机矩阵
    MatrixXd random = MatrixXd::Random(2, 2);
    
    // 6. 打印矩阵
    std::cout << "A矩阵:\n" << A << std::endl;
    std::cout << "多项式系数矩阵:\n" << poly_coeff << std::endl;
    
    return 0;
}
