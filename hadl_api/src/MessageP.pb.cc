// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageP.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* MessageP_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MessageP_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageP_2eproto() {
  protobuf_AddDesc_MessageP_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageP.proto");
  GOOGLE_CHECK(file != NULL);
  MessageP_descriptor_ = file->message_type(0);
  static const int MessageP_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageP, sender_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageP, receiver_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageP, code_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageP, argument_),
  };
  MessageP_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MessageP_descriptor_,
      MessageP::default_instance_,
      MessageP_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageP, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MessageP, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MessageP));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageP_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MessageP_descriptor_, &MessageP::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageP_2eproto() {
  delete MessageP::default_instance_;
  delete MessageP_reflection_;
}

void protobuf_AddDesc_MessageP_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016MessageP.proto\"L\n\010MessageP\022\016\n\006sender\030\001"
    " \002(\t\022\020\n\010receiver\030\002 \002(\t\022\014\n\004code\030\003 \002(\005\022\020\n\010"
    "argument\030\004 \003(\t", 94);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageP.proto", &protobuf_RegisterTypes);
  MessageP::default_instance_ = new MessageP();
  MessageP::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageP_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageP_2eproto {
  StaticDescriptorInitializer_MessageP_2eproto() {
    protobuf_AddDesc_MessageP_2eproto();
  }
} static_descriptor_initializer_MessageP_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int MessageP::kSenderFieldNumber;
const int MessageP::kReceiverFieldNumber;
const int MessageP::kCodeFieldNumber;
const int MessageP::kArgumentFieldNumber;
#endif  // !_MSC_VER

MessageP::MessageP()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void MessageP::InitAsDefaultInstance() {
}

MessageP::MessageP(const MessageP& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void MessageP::SharedCtor() {
  _cached_size_ = 0;
  sender_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  receiver_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  code_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MessageP::~MessageP() {
  SharedDtor();
}

void MessageP::SharedDtor() {
  if (sender_ != &::google::protobuf::internal::kEmptyString) {
    delete sender_;
  }
  if (receiver_ != &::google::protobuf::internal::kEmptyString) {
    delete receiver_;
  }
  if (this != default_instance_) {
  }
}

void MessageP::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MessageP::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageP_descriptor_;
}

const MessageP& MessageP::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageP_2eproto();  return *default_instance_;
}

MessageP* MessageP::default_instance_ = NULL;

MessageP* MessageP::New() const {
  return new MessageP;
}

void MessageP::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_sender()) {
      if (sender_ != &::google::protobuf::internal::kEmptyString) {
        sender_->clear();
      }
    }
    if (has_receiver()) {
      if (receiver_ != &::google::protobuf::internal::kEmptyString) {
        receiver_->clear();
      }
    }
    code_ = 0;
  }
  argument_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MessageP::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string sender = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sender()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->sender().data(), this->sender().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_receiver;
        break;
      }
      
      // required string receiver = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_receiver:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_receiver()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->receiver().data(), this->receiver().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_code;
        break;
      }
      
      // required int32 code = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_code:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &code_)));
          set_has_code();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_argument;
        break;
      }
      
      // repeated string argument = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_argument:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_argument()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->argument(0).data(), this->argument(0).length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_argument;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void MessageP::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string sender = 1;
  if (has_sender()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->sender().data(), this->sender().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->sender(), output);
  }
  
  // required string receiver = 2;
  if (has_receiver()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->receiver().data(), this->receiver().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->receiver(), output);
  }
  
  // required int32 code = 3;
  if (has_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->code(), output);
  }
  
  // repeated string argument = 4;
  for (int i = 0; i < this->argument_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8String(
    this->argument(i).data(), this->argument(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->argument(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* MessageP::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string sender = 1;
  if (has_sender()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->sender().data(), this->sender().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->sender(), target);
  }
  
  // required string receiver = 2;
  if (has_receiver()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->receiver().data(), this->receiver().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->receiver(), target);
  }
  
  // required int32 code = 3;
  if (has_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->code(), target);
  }
  
  // repeated string argument = 4;
  for (int i = 0; i < this->argument_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->argument(i).data(), this->argument(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->argument(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int MessageP::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string sender = 1;
    if (has_sender()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->sender());
    }
    
    // required string receiver = 2;
    if (has_receiver()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->receiver());
    }
    
    // required int32 code = 3;
    if (has_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->code());
    }
    
  }
  // repeated string argument = 4;
  total_size += 1 * this->argument_size();
  for (int i = 0; i < this->argument_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->argument(i));
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MessageP::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MessageP* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MessageP*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MessageP::MergeFrom(const MessageP& from) {
  GOOGLE_CHECK_NE(&from, this);
  argument_.MergeFrom(from.argument_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_sender()) {
      set_sender(from.sender());
    }
    if (from.has_receiver()) {
      set_receiver(from.receiver());
    }
    if (from.has_code()) {
      set_code(from.code());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MessageP::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessageP::CopyFrom(const MessageP& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageP::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void MessageP::Swap(MessageP* other) {
  if (other != this) {
    std::swap(sender_, other->sender_);
    std::swap(receiver_, other->receiver_);
    std::swap(code_, other->code_);
    argument_.Swap(&other->argument_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MessageP::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MessageP_descriptor_;
  metadata.reflection = MessageP_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
