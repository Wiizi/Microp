/**
  ******************************************************************************
  * File Name          : filter.c
  * Description        : A program which using kalman filter to filter the noise
  * Author			  		 : Chuan Qin, Wei Wang
  * Version            : 1.0.0
  * Date			  			 : Feburary 14th, 2016
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include "data.h"


/**
   * @brief Initializes the kalman filter state
   * @param  kstate: kalman filter state
   * @retval 0 when the initialization is done
   */
void Kstate_Initialization(struct kalman_state* kstate){
	kstate->q = DEF_q;
	kstate->r = DEF_r;
	kstate->x = DEF_x;
	kstate->p = DEF_p;
	kstate->k = DEF_k;
}

/**
   * @brief Set the parameters (q, r)
   * @param  kstate: kalman filter state
   * @param  newQ: new q value
   * @param  newR: new r value
   * @param  newX: new x value
   * @retval 0 when the initialization is done
   */
void Set_Kstate_Parameters(struct kalman_state* kstate, float newQ, float newR, float newX){
	kstate->q = newQ;
	kstate->r = newR;
	kstate->x = newX;
}

/**
   * @brief Updates the esetimated value x using kalman filter
   * @param  kstate: kalman filter state
   * @param  measurement: the value that need to be filtered
   * @retval the filtered x value
   */
float Kalmanfilter_C(struct kalman_state* kstate, float measurement){
	kstate->p = kstate->p + kstate->q;
	kstate->k = kstate->p / (kstate->p + kstate->r);
	kstate->x = kstate->x + kstate->k * (measurement - kstate->x);
	kstate->p = (1 - kstate->k) * kstate->p;
	
	if (kstate->x == NAN || kstate->x == INFINITY){
		return 0;
	}
	return kstate->x;
}
