// Eigen 基础使用示例
#include <iostream>
#include <Eigen/Dense>

int main() {
    // 1. 创建矩阵的几种方式
    std::cout << "=== 创建矩阵 ===" << std::endl;
    
    // 创建 3x3 的零矩阵
    Eigen::MatrixXd mat1 = Eigen::MatrixXd::Zero(3, 3);
    std::cout << "3x3 零矩阵:\n" << mat1 << std::endl << std::endl;
    
    // 创建 2x4 的矩阵并初始化
    Eigen::MatrixXd mat2(2, 4);
    mat2 << 1, 2, 3, 4,
            5, 6, 7, 8;
    std::cout << "2x4 初始化矩阵:\n" << mat2 << std::endl << std::endl;
    
    // 2. 多项式系数矩阵示例（模拟 HPI_poly_coeff_ 的用途）
    std::cout << "=== 多项式系数矩阵示例 ===" << std::endl;
    
    // 假设有3段轨迹，每段用5次多项式表示：y = a5*t^5 + a4*t^4 + a3*t^3 + a2*t^2 + a1*t + a0
    // 矩阵每行代表一段轨迹的6个系数 [a0, a1, a2, a3, a4, a5]
    Eigen::MatrixXd poly_coeff(3, 6);
    poly_coeff << 0.0, 1.0, 0.5, 0.1, 0.0, 0.0,  // 第1段轨迹系数
                  2.0, 1.5, 0.3, 0.2, 0.1, 0.0,  // 第2段轨迹系数  
                  1.0, 2.0, 0.0, 0.3, 0.0, 0.0;  // 第3段轨迹系数
    
    std::cout << "轨迹多项式系数矩阵 (3段轨迹 x 6个系数):\n" << poly_coeff << std::endl << std::endl;
    
    // 3. 基本操作
    std::cout << "=== 基本操作 ===" << std::endl;
    
    // 获取矩阵尺寸
    std::cout << "矩阵行数: " << poly_coeff.rows() << std::endl;
    std::cout << "矩阵列数: " << poly_coeff.cols() << std::endl;
    
    // 访问元素（索引从0开始）
    std::cout << "第1段轨迹的常数项系数: " << poly_coeff(0, 0) << std::endl;
    std::cout << "第2段轨迹的线性项系数: " << poly_coeff(1, 1) << std::endl;
    
    // 获取某一行（某段轨迹的所有系数）
    Eigen::VectorXd first_trajectory_coeffs = poly_coeff.row(0);
    std::cout << "第1段轨迹系数: " << first_trajectory_coeffs.transpose() << std::endl;
    
    // 4. 使用多项式计算轨迹点
    std::cout << "\n=== 轨迹计算示例 ===" << std::endl;
    
    // 计算第1段轨迹在 t=1.0 时的位置
    double t = 1.0;
    Eigen::VectorXd t_powers(6);
    t_powers << 1, t, t*t, t*t*t, t*t*t*t, t*t*t*t*t;  // [1, t, t^2, t^3, t^4, t^5]
    
    double position = first_trajectory_coeffs.dot(t_powers);
    std::cout << "第1段轨迹在 t=" << t << " 时的位置: " << position << std::endl;
    
    return 0;
}
