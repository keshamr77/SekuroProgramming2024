;; Auto-generated. Do not edit!


(when (boundp 'demo_package::MagnitudeCalculation)
  (if (not (find-package "DEMO_PACKAGE"))
    (make-package "DEMO_PACKAGE"))
  (shadow 'MagnitudeCalculation (find-package "DEMO_PACKAGE")))
(unless (find-package "DEMO_PACKAGE::MAGNITUDECALCULATION")
  (make-package "DEMO_PACKAGE::MAGNITUDECALCULATION"))
(unless (find-package "DEMO_PACKAGE::MAGNITUDECALCULATIONREQUEST")
  (make-package "DEMO_PACKAGE::MAGNITUDECALCULATIONREQUEST"))
(unless (find-package "DEMO_PACKAGE::MAGNITUDECALCULATIONRESPONSE")
  (make-package "DEMO_PACKAGE::MAGNITUDECALCULATIONRESPONSE"))

(in-package "ROS")





(defclass demo_package::MagnitudeCalculationRequest
  :super ros::object
  :slots (_komponenX _komponenY _komponenZ ))

(defmethod demo_package::MagnitudeCalculationRequest
  (:init
   (&key
    ((:komponenX __komponenX) 0.0)
    ((:komponenY __komponenY) 0.0)
    ((:komponenZ __komponenZ) 0.0)
    )
   (send-super :init)
   (setq _komponenX (float __komponenX))
   (setq _komponenY (float __komponenY))
   (setq _komponenZ (float __komponenZ))
   self)
  (:komponenX
   (&optional __komponenX)
   (if __komponenX (setq _komponenX __komponenX)) _komponenX)
  (:komponenY
   (&optional __komponenY)
   (if __komponenY (setq _komponenY __komponenY)) _komponenY)
  (:komponenZ
   (&optional __komponenZ)
   (if __komponenZ (setq _komponenZ __komponenZ)) _komponenZ)
  (:serialization-length
   ()
   (+
    ;; float64 _komponenX
    8
    ;; float64 _komponenY
    8
    ;; float64 _komponenZ
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _komponenX
       (sys::poke _komponenX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenY
       (sys::poke _komponenY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenZ
       (sys::poke _komponenZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _komponenX
     (setq _komponenX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenY
     (setq _komponenY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenZ
     (setq _komponenZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass demo_package::MagnitudeCalculationResponse
  :super ros::object
  :slots (_magnitude ))

(defmethod demo_package::MagnitudeCalculationResponse
  (:init
   (&key
    ((:magnitude __magnitude) 0.0)
    )
   (send-super :init)
   (setq _magnitude (float __magnitude))
   self)
  (:magnitude
   (&optional __magnitude)
   (if __magnitude (setq _magnitude __magnitude)) _magnitude)
  (:serialization-length
   ()
   (+
    ;; float64 _magnitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _magnitude
       (sys::poke _magnitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _magnitude
     (setq _magnitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass demo_package::MagnitudeCalculation
  :super ros::object
  :slots ())

(setf (get demo_package::MagnitudeCalculation :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get demo_package::MagnitudeCalculation :datatype-) "demo_package/MagnitudeCalculation")
(setf (get demo_package::MagnitudeCalculation :request) demo_package::MagnitudeCalculationRequest)
(setf (get demo_package::MagnitudeCalculation :response) demo_package::MagnitudeCalculationResponse)

(defmethod demo_package::MagnitudeCalculationRequest
  (:response () (instance demo_package::MagnitudeCalculationResponse :init)))

(setf (get demo_package::MagnitudeCalculationRequest :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get demo_package::MagnitudeCalculationRequest :datatype-) "demo_package/MagnitudeCalculationRequest")
(setf (get demo_package::MagnitudeCalculationRequest :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")

(setf (get demo_package::MagnitudeCalculationResponse :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get demo_package::MagnitudeCalculationResponse :datatype-) "demo_package/MagnitudeCalculationResponse")
(setf (get demo_package::MagnitudeCalculationResponse :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")



(provide :demo_package/MagnitudeCalculation "55d1a215f43fd1f64eb105a505b172c4")


