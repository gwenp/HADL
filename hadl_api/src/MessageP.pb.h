// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageP.proto

#ifndef PROTOBUF_MessageP_2eproto__INCLUDED
#define PROTOBUF_MessageP_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessageP_2eproto();
void protobuf_AssignDesc_MessageP_2eproto();
void protobuf_ShutdownFile_MessageP_2eproto();

class MessageP;

enum MessageP_MessageType {
  MessageP_MessageType_REQUEST = 0,
  MessageP_MessageType_RESPONSE = 1,
  MessageP_MessageType_DISCOVER = 2,
  MessageP_MessageType_INFO = 3,
  MessageP_MessageType_DISCONNECT = 4
};
bool MessageP_MessageType_IsValid(int value);
const MessageP_MessageType MessageP_MessageType_MessageType_MIN = MessageP_MessageType_REQUEST;
const MessageP_MessageType MessageP_MessageType_MessageType_MAX = MessageP_MessageType_DISCONNECT;
const int MessageP_MessageType_MessageType_ARRAYSIZE = MessageP_MessageType_MessageType_MAX + 1;

const ::google::protobuf::EnumDescriptor* MessageP_MessageType_descriptor();
inline const ::std::string& MessageP_MessageType_Name(MessageP_MessageType value) {
  return ::google::protobuf::internal::NameOfEnum(
    MessageP_MessageType_descriptor(), value);
}
inline bool MessageP_MessageType_Parse(
    const ::std::string& name, MessageP_MessageType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MessageP_MessageType>(
    MessageP_MessageType_descriptor(), name, value);
}
enum MessageP_DiscoverType {
  MessageP_DiscoverType_PROVIDED = 0,
  MessageP_DiscoverType_REQUIRED = 1
};
bool MessageP_DiscoverType_IsValid(int value);
const MessageP_DiscoverType MessageP_DiscoverType_DiscoverType_MIN = MessageP_DiscoverType_PROVIDED;
const MessageP_DiscoverType MessageP_DiscoverType_DiscoverType_MAX = MessageP_DiscoverType_REQUIRED;
const int MessageP_DiscoverType_DiscoverType_ARRAYSIZE = MessageP_DiscoverType_DiscoverType_MAX + 1;

const ::google::protobuf::EnumDescriptor* MessageP_DiscoverType_descriptor();
inline const ::std::string& MessageP_DiscoverType_Name(MessageP_DiscoverType value) {
  return ::google::protobuf::internal::NameOfEnum(
    MessageP_DiscoverType_descriptor(), value);
}
inline bool MessageP_DiscoverType_Parse(
    const ::std::string& name, MessageP_DiscoverType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MessageP_DiscoverType>(
    MessageP_DiscoverType_descriptor(), name, value);
}
// ===================================================================

class MessageP : public ::google::protobuf::Message {
 public:
  MessageP();
  virtual ~MessageP();
  
  MessageP(const MessageP& from);
  
  inline MessageP& operator=(const MessageP& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const MessageP& default_instance();
  
  void Swap(MessageP* other);
  
  // implements Message ----------------------------------------------
  
  MessageP* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageP& from);
  void MergeFrom(const MessageP& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef MessageP_MessageType MessageType;
  static const MessageType REQUEST = MessageP_MessageType_REQUEST;
  static const MessageType RESPONSE = MessageP_MessageType_RESPONSE;
  static const MessageType DISCOVER = MessageP_MessageType_DISCOVER;
  static const MessageType INFO = MessageP_MessageType_INFO;
  static const MessageType DISCONNECT = MessageP_MessageType_DISCONNECT;
  static inline bool MessageType_IsValid(int value) {
    return MessageP_MessageType_IsValid(value);
  }
  static const MessageType MessageType_MIN =
    MessageP_MessageType_MessageType_MIN;
  static const MessageType MessageType_MAX =
    MessageP_MessageType_MessageType_MAX;
  static const int MessageType_ARRAYSIZE =
    MessageP_MessageType_MessageType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  MessageType_descriptor() {
    return MessageP_MessageType_descriptor();
  }
  static inline const ::std::string& MessageType_Name(MessageType value) {
    return MessageP_MessageType_Name(value);
  }
  static inline bool MessageType_Parse(const ::std::string& name,
      MessageType* value) {
    return MessageP_MessageType_Parse(name, value);
  }
  
  typedef MessageP_DiscoverType DiscoverType;
  static const DiscoverType PROVIDED = MessageP_DiscoverType_PROVIDED;
  static const DiscoverType REQUIRED = MessageP_DiscoverType_REQUIRED;
  static inline bool DiscoverType_IsValid(int value) {
    return MessageP_DiscoverType_IsValid(value);
  }
  static const DiscoverType DiscoverType_MIN =
    MessageP_DiscoverType_DiscoverType_MIN;
  static const DiscoverType DiscoverType_MAX =
    MessageP_DiscoverType_DiscoverType_MAX;
  static const int DiscoverType_ARRAYSIZE =
    MessageP_DiscoverType_DiscoverType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  DiscoverType_descriptor() {
    return MessageP_DiscoverType_descriptor();
  }
  static inline const ::std::string& DiscoverType_Name(DiscoverType value) {
    return MessageP_DiscoverType_Name(value);
  }
  static inline bool DiscoverType_Parse(const ::std::string& name,
      DiscoverType* value) {
    return MessageP_DiscoverType_Parse(name, value);
  }
  
  // accessors -------------------------------------------------------
  
  // required .MessageP.MessageType type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::MessageP_MessageType type() const;
  inline void set_type(::MessageP_MessageType value);
  
  // required string sender = 2;
  inline bool has_sender() const;
  inline void clear_sender();
  static const int kSenderFieldNumber = 2;
  inline const ::std::string& sender() const;
  inline void set_sender(const ::std::string& value);
  inline void set_sender(const char* value);
  inline void set_sender(const char* value, size_t size);
  inline ::std::string* mutable_sender();
  inline ::std::string* release_sender();
  
  // required string receiver = 3;
  inline bool has_receiver() const;
  inline void clear_receiver();
  static const int kReceiverFieldNumber = 3;
  inline const ::std::string& receiver() const;
  inline void set_receiver(const ::std::string& value);
  inline void set_receiver(const char* value);
  inline void set_receiver(const char* value, size_t size);
  inline ::std::string* mutable_receiver();
  inline ::std::string* release_receiver();
  
  // optional int32 code = 4;
  inline bool has_code() const;
  inline void clear_code();
  static const int kCodeFieldNumber = 4;
  inline ::google::protobuf::int32 code() const;
  inline void set_code(::google::protobuf::int32 value);
  
  // repeated string argument = 5;
  inline int argument_size() const;
  inline void clear_argument();
  static const int kArgumentFieldNumber = 5;
  inline const ::std::string& argument(int index) const;
  inline ::std::string* mutable_argument(int index);
  inline void set_argument(int index, const ::std::string& value);
  inline void set_argument(int index, const char* value);
  inline void set_argument(int index, const char* value, size_t size);
  inline ::std::string* add_argument();
  inline void add_argument(const ::std::string& value);
  inline void add_argument(const char* value);
  inline void add_argument(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& argument() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_argument();
  
  // optional .MessageP.DiscoverType discover_type = 6;
  inline bool has_discover_type() const;
  inline void clear_discover_type();
  static const int kDiscoverTypeFieldNumber = 6;
  inline ::MessageP_DiscoverType discover_type() const;
  inline void set_discover_type(::MessageP_DiscoverType value);
  
  // @@protoc_insertion_point(class_scope:MessageP)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_sender();
  inline void clear_has_sender();
  inline void set_has_receiver();
  inline void clear_has_receiver();
  inline void set_has_code();
  inline void clear_has_code();
  inline void set_has_discover_type();
  inline void clear_has_discover_type();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* sender_;
  int type_;
  ::google::protobuf::int32 code_;
  ::std::string* receiver_;
  ::google::protobuf::RepeatedPtrField< ::std::string> argument_;
  int discover_type_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];
  
  friend void  protobuf_AddDesc_MessageP_2eproto();
  friend void protobuf_AssignDesc_MessageP_2eproto();
  friend void protobuf_ShutdownFile_MessageP_2eproto();
  
  void InitAsDefaultInstance();
  static MessageP* default_instance_;
};
// ===================================================================


// ===================================================================

// MessageP

// required .MessageP.MessageType type = 1;
inline bool MessageP::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MessageP::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MessageP::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MessageP::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::MessageP_MessageType MessageP::type() const {
  return static_cast< ::MessageP_MessageType >(type_);
}
inline void MessageP::set_type(::MessageP_MessageType value) {
  GOOGLE_DCHECK(::MessageP_MessageType_IsValid(value));
  set_has_type();
  type_ = value;
}

// required string sender = 2;
inline bool MessageP::has_sender() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MessageP::set_has_sender() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MessageP::clear_has_sender() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MessageP::clear_sender() {
  if (sender_ != &::google::protobuf::internal::kEmptyString) {
    sender_->clear();
  }
  clear_has_sender();
}
inline const ::std::string& MessageP::sender() const {
  return *sender_;
}
inline void MessageP::set_sender(const ::std::string& value) {
  set_has_sender();
  if (sender_ == &::google::protobuf::internal::kEmptyString) {
    sender_ = new ::std::string;
  }
  sender_->assign(value);
}
inline void MessageP::set_sender(const char* value) {
  set_has_sender();
  if (sender_ == &::google::protobuf::internal::kEmptyString) {
    sender_ = new ::std::string;
  }
  sender_->assign(value);
}
inline void MessageP::set_sender(const char* value, size_t size) {
  set_has_sender();
  if (sender_ == &::google::protobuf::internal::kEmptyString) {
    sender_ = new ::std::string;
  }
  sender_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MessageP::mutable_sender() {
  set_has_sender();
  if (sender_ == &::google::protobuf::internal::kEmptyString) {
    sender_ = new ::std::string;
  }
  return sender_;
}
inline ::std::string* MessageP::release_sender() {
  clear_has_sender();
  if (sender_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = sender_;
    sender_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string receiver = 3;
inline bool MessageP::has_receiver() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MessageP::set_has_receiver() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MessageP::clear_has_receiver() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MessageP::clear_receiver() {
  if (receiver_ != &::google::protobuf::internal::kEmptyString) {
    receiver_->clear();
  }
  clear_has_receiver();
}
inline const ::std::string& MessageP::receiver() const {
  return *receiver_;
}
inline void MessageP::set_receiver(const ::std::string& value) {
  set_has_receiver();
  if (receiver_ == &::google::protobuf::internal::kEmptyString) {
    receiver_ = new ::std::string;
  }
  receiver_->assign(value);
}
inline void MessageP::set_receiver(const char* value) {
  set_has_receiver();
  if (receiver_ == &::google::protobuf::internal::kEmptyString) {
    receiver_ = new ::std::string;
  }
  receiver_->assign(value);
}
inline void MessageP::set_receiver(const char* value, size_t size) {
  set_has_receiver();
  if (receiver_ == &::google::protobuf::internal::kEmptyString) {
    receiver_ = new ::std::string;
  }
  receiver_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MessageP::mutable_receiver() {
  set_has_receiver();
  if (receiver_ == &::google::protobuf::internal::kEmptyString) {
    receiver_ = new ::std::string;
  }
  return receiver_;
}
inline ::std::string* MessageP::release_receiver() {
  clear_has_receiver();
  if (receiver_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = receiver_;
    receiver_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional int32 code = 4;
inline bool MessageP::has_code() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void MessageP::set_has_code() {
  _has_bits_[0] |= 0x00000008u;
}
inline void MessageP::clear_has_code() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void MessageP::clear_code() {
  code_ = 0;
  clear_has_code();
}
inline ::google::protobuf::int32 MessageP::code() const {
  return code_;
}
inline void MessageP::set_code(::google::protobuf::int32 value) {
  set_has_code();
  code_ = value;
}

// repeated string argument = 5;
inline int MessageP::argument_size() const {
  return argument_.size();
}
inline void MessageP::clear_argument() {
  argument_.Clear();
}
inline const ::std::string& MessageP::argument(int index) const {
  return argument_.Get(index);
}
inline ::std::string* MessageP::mutable_argument(int index) {
  return argument_.Mutable(index);
}
inline void MessageP::set_argument(int index, const ::std::string& value) {
  argument_.Mutable(index)->assign(value);
}
inline void MessageP::set_argument(int index, const char* value) {
  argument_.Mutable(index)->assign(value);
}
inline void MessageP::set_argument(int index, const char* value, size_t size) {
  argument_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* MessageP::add_argument() {
  return argument_.Add();
}
inline void MessageP::add_argument(const ::std::string& value) {
  argument_.Add()->assign(value);
}
inline void MessageP::add_argument(const char* value) {
  argument_.Add()->assign(value);
}
inline void MessageP::add_argument(const char* value, size_t size) {
  argument_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
MessageP::argument() const {
  return argument_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
MessageP::mutable_argument() {
  return &argument_;
}

// optional .MessageP.DiscoverType discover_type = 6;
inline bool MessageP::has_discover_type() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void MessageP::set_has_discover_type() {
  _has_bits_[0] |= 0x00000020u;
}
inline void MessageP::clear_has_discover_type() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void MessageP::clear_discover_type() {
  discover_type_ = 0;
  clear_has_discover_type();
}
inline ::MessageP_DiscoverType MessageP::discover_type() const {
  return static_cast< ::MessageP_DiscoverType >(discover_type_);
}
inline void MessageP::set_discover_type(::MessageP_DiscoverType value) {
  GOOGLE_DCHECK(::MessageP_DiscoverType_IsValid(value));
  set_has_discover_type();
  discover_type_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MessageP_MessageType>() {
  return ::MessageP_MessageType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MessageP_DiscoverType>() {
  return ::MessageP_DiscoverType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageP_2eproto__INCLUDED
