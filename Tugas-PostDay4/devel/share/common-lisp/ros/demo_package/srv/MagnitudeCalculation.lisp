; Auto-generated. Do not edit!


(cl:in-package demo_package-srv)


;//! \htmlinclude MagnitudeCalculation-request.msg.html

(cl:defclass <MagnitudeCalculation-request> (roslisp-msg-protocol:ros-message)
  ((komponenX
    :reader komponenX
    :initarg :komponenX
    :type cl:float
    :initform 0.0)
   (komponenY
    :reader komponenY
    :initarg :komponenY
    :type cl:float
    :initform 0.0)
   (komponenZ
    :reader komponenZ
    :initarg :komponenZ
    :type cl:float
    :initform 0.0))
)

(cl:defclass MagnitudeCalculation-request (<MagnitudeCalculation-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MagnitudeCalculation-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MagnitudeCalculation-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name demo_package-srv:<MagnitudeCalculation-request> is deprecated: use demo_package-srv:MagnitudeCalculation-request instead.")))

(cl:ensure-generic-function 'komponenX-val :lambda-list '(m))
(cl:defmethod komponenX-val ((m <MagnitudeCalculation-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-srv:komponenX-val is deprecated.  Use demo_package-srv:komponenX instead.")
  (komponenX m))

(cl:ensure-generic-function 'komponenY-val :lambda-list '(m))
(cl:defmethod komponenY-val ((m <MagnitudeCalculation-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-srv:komponenY-val is deprecated.  Use demo_package-srv:komponenY instead.")
  (komponenY m))

(cl:ensure-generic-function 'komponenZ-val :lambda-list '(m))
(cl:defmethod komponenZ-val ((m <MagnitudeCalculation-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-srv:komponenZ-val is deprecated.  Use demo_package-srv:komponenZ instead.")
  (komponenZ m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MagnitudeCalculation-request>) ostream)
  "Serializes a message object of type '<MagnitudeCalculation-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'komponenX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'komponenY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'komponenZ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MagnitudeCalculation-request>) istream)
  "Deserializes a message object of type '<MagnitudeCalculation-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'komponenX) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'komponenY) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'komponenZ) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MagnitudeCalculation-request>)))
  "Returns string type for a service object of type '<MagnitudeCalculation-request>"
  "demo_package/MagnitudeCalculationRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MagnitudeCalculation-request)))
  "Returns string type for a service object of type 'MagnitudeCalculation-request"
  "demo_package/MagnitudeCalculationRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MagnitudeCalculation-request>)))
  "Returns md5sum for a message object of type '<MagnitudeCalculation-request>"
  "55d1a215f43fd1f64eb105a505b172c4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MagnitudeCalculation-request)))
  "Returns md5sum for a message object of type 'MagnitudeCalculation-request"
  "55d1a215f43fd1f64eb105a505b172c4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MagnitudeCalculation-request>)))
  "Returns full string definition for message of type '<MagnitudeCalculation-request>"
  (cl:format cl:nil "float64 komponenX~%float64 komponenY~%float64 komponenZ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MagnitudeCalculation-request)))
  "Returns full string definition for message of type 'MagnitudeCalculation-request"
  (cl:format cl:nil "float64 komponenX~%float64 komponenY~%float64 komponenZ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MagnitudeCalculation-request>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MagnitudeCalculation-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MagnitudeCalculation-request
    (cl:cons ':komponenX (komponenX msg))
    (cl:cons ':komponenY (komponenY msg))
    (cl:cons ':komponenZ (komponenZ msg))
))
;//! \htmlinclude MagnitudeCalculation-response.msg.html

(cl:defclass <MagnitudeCalculation-response> (roslisp-msg-protocol:ros-message)
  ((magnitude
    :reader magnitude
    :initarg :magnitude
    :type cl:float
    :initform 0.0))
)

(cl:defclass MagnitudeCalculation-response (<MagnitudeCalculation-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MagnitudeCalculation-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MagnitudeCalculation-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name demo_package-srv:<MagnitudeCalculation-response> is deprecated: use demo_package-srv:MagnitudeCalculation-response instead.")))

(cl:ensure-generic-function 'magnitude-val :lambda-list '(m))
(cl:defmethod magnitude-val ((m <MagnitudeCalculation-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-srv:magnitude-val is deprecated.  Use demo_package-srv:magnitude instead.")
  (magnitude m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MagnitudeCalculation-response>) ostream)
  "Serializes a message object of type '<MagnitudeCalculation-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'magnitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MagnitudeCalculation-response>) istream)
  "Deserializes a message object of type '<MagnitudeCalculation-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'magnitude) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MagnitudeCalculation-response>)))
  "Returns string type for a service object of type '<MagnitudeCalculation-response>"
  "demo_package/MagnitudeCalculationResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MagnitudeCalculation-response)))
  "Returns string type for a service object of type 'MagnitudeCalculation-response"
  "demo_package/MagnitudeCalculationResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MagnitudeCalculation-response>)))
  "Returns md5sum for a message object of type '<MagnitudeCalculation-response>"
  "55d1a215f43fd1f64eb105a505b172c4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MagnitudeCalculation-response)))
  "Returns md5sum for a message object of type 'MagnitudeCalculation-response"
  "55d1a215f43fd1f64eb105a505b172c4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MagnitudeCalculation-response>)))
  "Returns full string definition for message of type '<MagnitudeCalculation-response>"
  (cl:format cl:nil "float64 magnitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MagnitudeCalculation-response)))
  "Returns full string definition for message of type 'MagnitudeCalculation-response"
  (cl:format cl:nil "float64 magnitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MagnitudeCalculation-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MagnitudeCalculation-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MagnitudeCalculation-response
    (cl:cons ':magnitude (magnitude msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MagnitudeCalculation)))
  'MagnitudeCalculation-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MagnitudeCalculation)))
  'MagnitudeCalculation-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MagnitudeCalculation)))
  "Returns string type for a service object of type '<MagnitudeCalculation>"
  "demo_package/MagnitudeCalculation")