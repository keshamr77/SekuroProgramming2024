; Auto-generated. Do not edit!


(cl:in-package demo_package-msg)


;//! \htmlinclude Topic.msg.html

(cl:defclass <Topic> (roslisp-msg-protocol:ros-message)
  ((usia
    :reader usia
    :initarg :usia
    :type cl:integer
    :initform 0)
   (tinggi
    :reader tinggi
    :initarg :tinggi
    :type cl:float
    :initform 0.0)
   (nama
    :reader nama
    :initarg :nama
    :type cl:string
    :initform "")
   (kehadiran
    :reader kehadiran
    :initarg :kehadiran
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Topic (<Topic>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Topic>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Topic)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name demo_package-msg:<Topic> is deprecated: use demo_package-msg:Topic instead.")))

(cl:ensure-generic-function 'usia-val :lambda-list '(m))
(cl:defmethod usia-val ((m <Topic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-msg:usia-val is deprecated.  Use demo_package-msg:usia instead.")
  (usia m))

(cl:ensure-generic-function 'tinggi-val :lambda-list '(m))
(cl:defmethod tinggi-val ((m <Topic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-msg:tinggi-val is deprecated.  Use demo_package-msg:tinggi instead.")
  (tinggi m))

(cl:ensure-generic-function 'nama-val :lambda-list '(m))
(cl:defmethod nama-val ((m <Topic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-msg:nama-val is deprecated.  Use demo_package-msg:nama instead.")
  (nama m))

(cl:ensure-generic-function 'kehadiran-val :lambda-list '(m))
(cl:defmethod kehadiran-val ((m <Topic>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_package-msg:kehadiran-val is deprecated.  Use demo_package-msg:kehadiran instead.")
  (kehadiran m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Topic>) ostream)
  "Serializes a message object of type '<Topic>"
  (cl:let* ((signed (cl:slot-value msg 'usia)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'tinggi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'nama))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'nama))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'kehadiran) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Topic>) istream)
  "Deserializes a message object of type '<Topic>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'usia) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'tinggi) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'nama) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'nama) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'kehadiran) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Topic>)))
  "Returns string type for a message object of type '<Topic>"
  "demo_package/Topic")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Topic)))
  "Returns string type for a message object of type 'Topic"
  "demo_package/Topic")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Topic>)))
  "Returns md5sum for a message object of type '<Topic>"
  "5ad8335939c8d987f5e0189e0ca2b800")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Topic)))
  "Returns md5sum for a message object of type 'Topic"
  "5ad8335939c8d987f5e0189e0ca2b800")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Topic>)))
  "Returns full string definition for message of type '<Topic>"
  (cl:format cl:nil "int64 usia~%float64 tinggi~%string nama~%bool kehadiran~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Topic)))
  "Returns full string definition for message of type 'Topic"
  (cl:format cl:nil "int64 usia~%float64 tinggi~%string nama~%bool kehadiran~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Topic>))
  (cl:+ 0
     8
     8
     4 (cl:length (cl:slot-value msg 'nama))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Topic>))
  "Converts a ROS message object to a list"
  (cl:list 'Topic
    (cl:cons ':usia (usia msg))
    (cl:cons ':tinggi (tinggi msg))
    (cl:cons ':nama (nama msg))
    (cl:cons ':kehadiran (kehadiran msg))
))
