
(cl:in-package :asdf)

(defsystem "demo_package-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MagnitudeCalculation" :depends-on ("_package_MagnitudeCalculation"))
    (:file "_package_MagnitudeCalculation" :depends-on ("_package"))
  ))