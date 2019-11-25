#ifndef PID_H
#define PID_H
#include <vector>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Helper for twiddle tune
   */
  void hyperparam_change(int index, double amount);

  /**
   * Twiddle tunes PID
   */
  double CalculateTwiddleIter(double cte);

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_, double Delta_T_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

 private:
  /**
   * PID Errors
   */
  double p_error;
  double prev_cte;
  double i_error;
  double d_error;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
  double Delta_T;

  /*
  * Twiddle variables
  */
  std::vector<double> dp;
  int step, param_index;
  // number of steps to allow changes to settle, then to evaluate error
  int n_settle_steps, n_eval_steps;
  double total_error, best_error;
  bool tried_adding, tried_subtracting, enable_twiddle;
};

#endif  // PID_H