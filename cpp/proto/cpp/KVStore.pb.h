// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: KVStore.proto

#ifndef PROTOBUF_KVStore_2eproto__INCLUDED
#define PROTOBUF_KVStore_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace kvstore_ns {
class KeyValueSet;
class KeyValueSetDefaultTypeInternal;
extern KeyValueSetDefaultTypeInternal _KeyValueSet_default_instance_;
class Transaction;
class TransactionDefaultTypeInternal;
extern TransactionDefaultTypeInternal _Transaction_default_instance_;
}  // namespace kvstore_ns

namespace kvstore_ns {

namespace protobuf_KVStore_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_KVStore_2eproto

enum DBASE_Action {
  DBASE_SET = 0,
  DBASE_Action_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DBASE_Action_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DBASE_Action_IsValid(int value);
const DBASE_Action DBASE_Action_MIN = DBASE_SET;
const DBASE_Action DBASE_Action_MAX = DBASE_SET;
const int DBASE_Action_ARRAYSIZE = DBASE_Action_MAX + 1;

const ::google::protobuf::EnumDescriptor* DBASE_Action_descriptor();
inline const ::std::string& DBASE_Action_Name(DBASE_Action value) {
  return ::google::protobuf::internal::NameOfEnum(
    DBASE_Action_descriptor(), value);
}
inline bool DBASE_Action_Parse(
    const ::std::string& name, DBASE_Action* value) {
  return ::google::protobuf::internal::ParseNamedEnum<DBASE_Action>(
    DBASE_Action_descriptor(), name, value);
}
enum TYPE_Info {
  TYPE_INT32 = 0,
  TYPE_INT64 = 1,
  TYPE_FLOAT = 2,
  TYPE_DOUBLE = 3,
  TYPE_BOOL = 4,
  TYPE_STRING = 5,
  TYPE_BYTES = 6,
  TYPE_EVENT = 7,
  TYPE_Info_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  TYPE_Info_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool TYPE_Info_IsValid(int value);
const TYPE_Info TYPE_Info_MIN = TYPE_INT32;
const TYPE_Info TYPE_Info_MAX = TYPE_EVENT;
const int TYPE_Info_ARRAYSIZE = TYPE_Info_MAX + 1;

const ::google::protobuf::EnumDescriptor* TYPE_Info_descriptor();
inline const ::std::string& TYPE_Info_Name(TYPE_Info value) {
  return ::google::protobuf::internal::NameOfEnum(
    TYPE_Info_descriptor(), value);
}
inline bool TYPE_Info_Parse(
    const ::std::string& name, TYPE_Info* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TYPE_Info>(
    TYPE_Info_descriptor(), name, value);
}
enum ARCH_Info {
  ARCH_BIG_ENDIAN = 0,
  ARCH_LITTLE_ENDIAN = 1,
  ARCH_Info_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ARCH_Info_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ARCH_Info_IsValid(int value);
const ARCH_Info ARCH_Info_MIN = ARCH_BIG_ENDIAN;
const ARCH_Info ARCH_Info_MAX = ARCH_LITTLE_ENDIAN;
const int ARCH_Info_ARRAYSIZE = ARCH_Info_MAX + 1;

const ::google::protobuf::EnumDescriptor* ARCH_Info_descriptor();
inline const ::std::string& ARCH_Info_Name(ARCH_Info value) {
  return ::google::protobuf::internal::NameOfEnum(
    ARCH_Info_descriptor(), value);
}
inline bool ARCH_Info_Parse(
    const ::std::string& name, ARCH_Info* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ARCH_Info>(
    ARCH_Info_descriptor(), name, value);
}
// ===================================================================

class KeyValueSet : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:kvstore_ns.KeyValueSet) */ {
 public:
  KeyValueSet();
  virtual ~KeyValueSet();

  KeyValueSet(const KeyValueSet& from);

  inline KeyValueSet& operator=(const KeyValueSet& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  KeyValueSet(KeyValueSet&& from) noexcept
    : KeyValueSet() {
    *this = ::std::move(from);
  }

  inline KeyValueSet& operator=(KeyValueSet&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const KeyValueSet& default_instance();

  static inline const KeyValueSet* internal_default_instance() {
    return reinterpret_cast<const KeyValueSet*>(
               &_KeyValueSet_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(KeyValueSet* other);
  friend void swap(KeyValueSet& a, KeyValueSet& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline KeyValueSet* New() const PROTOBUF_FINAL { return New(NULL); }

  KeyValueSet* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const KeyValueSet& from);
  void MergeFrom(const KeyValueSet& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(KeyValueSet* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string key = 1;
  void clear_key();
  static const int kKeyFieldNumber = 1;
  const ::std::string& key() const;
  void set_key(const ::std::string& value);
  #if LANG_CXX11
  void set_key(::std::string&& value);
  #endif
  void set_key(const char* value);
  void set_key(const char* value, size_t size);
  ::std::string* mutable_key();
  ::std::string* release_key();
  void set_allocated_key(::std::string* key);

  // bytes byteBuffer = 4;
  void clear_bytebuffer();
  static const int kByteBufferFieldNumber = 4;
  const ::std::string& bytebuffer() const;
  void set_bytebuffer(const ::std::string& value);
  #if LANG_CXX11
  void set_bytebuffer(::std::string&& value);
  #endif
  void set_bytebuffer(const char* value);
  void set_bytebuffer(const void* value, size_t size);
  ::std::string* mutable_bytebuffer();
  ::std::string* release_bytebuffer();
  void set_allocated_bytebuffer(::std::string* bytebuffer);

  // .kvstore_ns.TYPE_Info typeInfo = 2;
  void clear_typeinfo();
  static const int kTypeInfoFieldNumber = 2;
  ::kvstore_ns::TYPE_Info typeinfo() const;
  void set_typeinfo(::kvstore_ns::TYPE_Info value);

  // int32 numberElements = 3;
  void clear_numberelements();
  static const int kNumberElementsFieldNumber = 3;
  ::google::protobuf::int32 numberelements() const;
  void set_numberelements(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:kvstore_ns.KeyValueSet)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr key_;
  ::google::protobuf::internal::ArenaStringPtr bytebuffer_;
  int typeinfo_;
  ::google::protobuf::int32 numberelements_;
  mutable int _cached_size_;
  friend struct protobuf_KVStore_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Transaction : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:kvstore_ns.Transaction) */ {
 public:
  Transaction();
  virtual ~Transaction();

  Transaction(const Transaction& from);

  inline Transaction& operator=(const Transaction& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Transaction(Transaction&& from) noexcept
    : Transaction() {
    *this = ::std::move(from);
  }

  inline Transaction& operator=(Transaction&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Transaction& default_instance();

  static inline const Transaction* internal_default_instance() {
    return reinterpret_cast<const Transaction*>(
               &_Transaction_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Transaction* other);
  friend void swap(Transaction& a, Transaction& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Transaction* New() const PROTOBUF_FINAL { return New(NULL); }

  Transaction* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Transaction& from);
  void MergeFrom(const Transaction& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Transaction* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .kvstore_ns.KeyValueSet keyValueSet = 5;
  int keyvalueset_size() const;
  void clear_keyvalueset();
  static const int kKeyValueSetFieldNumber = 5;
  const ::kvstore_ns::KeyValueSet& keyvalueset(int index) const;
  ::kvstore_ns::KeyValueSet* mutable_keyvalueset(int index);
  ::kvstore_ns::KeyValueSet* add_keyvalueset();
  ::google::protobuf::RepeatedPtrField< ::kvstore_ns::KeyValueSet >*
      mutable_keyvalueset();
  const ::google::protobuf::RepeatedPtrField< ::kvstore_ns::KeyValueSet >&
      keyvalueset() const;

  // int64 timeStamp = 2;
  void clear_timestamp();
  static const int kTimeStampFieldNumber = 2;
  ::google::protobuf::int64 timestamp() const;
  void set_timestamp(::google::protobuf::int64 value);

  // int32 publisherID = 1;
  void clear_publisherid();
  static const int kPublisherIDFieldNumber = 1;
  ::google::protobuf::int32 publisherid() const;
  void set_publisherid(::google::protobuf::int32 value);

  // .kvstore_ns.DBASE_Action action = 3;
  void clear_action();
  static const int kActionFieldNumber = 3;
  ::kvstore_ns::DBASE_Action action() const;
  void set_action(::kvstore_ns::DBASE_Action value);

  // .kvstore_ns.ARCH_Info systemByteOrder = 4;
  void clear_systembyteorder();
  static const int kSystemByteOrderFieldNumber = 4;
  ::kvstore_ns::ARCH_Info systembyteorder() const;
  void set_systembyteorder(::kvstore_ns::ARCH_Info value);

  // @@protoc_insertion_point(class_scope:kvstore_ns.Transaction)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::kvstore_ns::KeyValueSet > keyvalueset_;
  ::google::protobuf::int64 timestamp_;
  ::google::protobuf::int32 publisherid_;
  int action_;
  int systembyteorder_;
  mutable int _cached_size_;
  friend struct protobuf_KVStore_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// KeyValueSet

// string key = 1;
inline void KeyValueSet::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& KeyValueSet::key() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.KeyValueSet.key)
  return key_.GetNoArena();
}
inline void KeyValueSet::set_key(const ::std::string& value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:kvstore_ns.KeyValueSet.key)
}
#if LANG_CXX11
inline void KeyValueSet::set_key(::std::string&& value) {
  
  key_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:kvstore_ns.KeyValueSet.key)
}
#endif
inline void KeyValueSet::set_key(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:kvstore_ns.KeyValueSet.key)
}
inline void KeyValueSet::set_key(const char* value, size_t size) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:kvstore_ns.KeyValueSet.key)
}
inline ::std::string* KeyValueSet::mutable_key() {
  
  // @@protoc_insertion_point(field_mutable:kvstore_ns.KeyValueSet.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* KeyValueSet::release_key() {
  // @@protoc_insertion_point(field_release:kvstore_ns.KeyValueSet.key)
  
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void KeyValueSet::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    
  } else {
    
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:kvstore_ns.KeyValueSet.key)
}

// .kvstore_ns.TYPE_Info typeInfo = 2;
inline void KeyValueSet::clear_typeinfo() {
  typeinfo_ = 0;
}
inline ::kvstore_ns::TYPE_Info KeyValueSet::typeinfo() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.KeyValueSet.typeInfo)
  return static_cast< ::kvstore_ns::TYPE_Info >(typeinfo_);
}
inline void KeyValueSet::set_typeinfo(::kvstore_ns::TYPE_Info value) {
  
  typeinfo_ = value;
  // @@protoc_insertion_point(field_set:kvstore_ns.KeyValueSet.typeInfo)
}

// int32 numberElements = 3;
inline void KeyValueSet::clear_numberelements() {
  numberelements_ = 0;
}
inline ::google::protobuf::int32 KeyValueSet::numberelements() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.KeyValueSet.numberElements)
  return numberelements_;
}
inline void KeyValueSet::set_numberelements(::google::protobuf::int32 value) {
  
  numberelements_ = value;
  // @@protoc_insertion_point(field_set:kvstore_ns.KeyValueSet.numberElements)
}

// bytes byteBuffer = 4;
inline void KeyValueSet::clear_bytebuffer() {
  bytebuffer_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& KeyValueSet::bytebuffer() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.KeyValueSet.byteBuffer)
  return bytebuffer_.GetNoArena();
}
inline void KeyValueSet::set_bytebuffer(const ::std::string& value) {
  
  bytebuffer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:kvstore_ns.KeyValueSet.byteBuffer)
}
#if LANG_CXX11
inline void KeyValueSet::set_bytebuffer(::std::string&& value) {
  
  bytebuffer_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:kvstore_ns.KeyValueSet.byteBuffer)
}
#endif
inline void KeyValueSet::set_bytebuffer(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  bytebuffer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:kvstore_ns.KeyValueSet.byteBuffer)
}
inline void KeyValueSet::set_bytebuffer(const void* value, size_t size) {
  
  bytebuffer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:kvstore_ns.KeyValueSet.byteBuffer)
}
inline ::std::string* KeyValueSet::mutable_bytebuffer() {
  
  // @@protoc_insertion_point(field_mutable:kvstore_ns.KeyValueSet.byteBuffer)
  return bytebuffer_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* KeyValueSet::release_bytebuffer() {
  // @@protoc_insertion_point(field_release:kvstore_ns.KeyValueSet.byteBuffer)
  
  return bytebuffer_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void KeyValueSet::set_allocated_bytebuffer(::std::string* bytebuffer) {
  if (bytebuffer != NULL) {
    
  } else {
    
  }
  bytebuffer_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), bytebuffer);
  // @@protoc_insertion_point(field_set_allocated:kvstore_ns.KeyValueSet.byteBuffer)
}

// -------------------------------------------------------------------

// Transaction

// int32 publisherID = 1;
inline void Transaction::clear_publisherid() {
  publisherid_ = 0;
}
inline ::google::protobuf::int32 Transaction::publisherid() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.Transaction.publisherID)
  return publisherid_;
}
inline void Transaction::set_publisherid(::google::protobuf::int32 value) {
  
  publisherid_ = value;
  // @@protoc_insertion_point(field_set:kvstore_ns.Transaction.publisherID)
}

// int64 timeStamp = 2;
inline void Transaction::clear_timestamp() {
  timestamp_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Transaction::timestamp() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.Transaction.timeStamp)
  return timestamp_;
}
inline void Transaction::set_timestamp(::google::protobuf::int64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:kvstore_ns.Transaction.timeStamp)
}

// .kvstore_ns.DBASE_Action action = 3;
inline void Transaction::clear_action() {
  action_ = 0;
}
inline ::kvstore_ns::DBASE_Action Transaction::action() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.Transaction.action)
  return static_cast< ::kvstore_ns::DBASE_Action >(action_);
}
inline void Transaction::set_action(::kvstore_ns::DBASE_Action value) {
  
  action_ = value;
  // @@protoc_insertion_point(field_set:kvstore_ns.Transaction.action)
}

// .kvstore_ns.ARCH_Info systemByteOrder = 4;
inline void Transaction::clear_systembyteorder() {
  systembyteorder_ = 0;
}
inline ::kvstore_ns::ARCH_Info Transaction::systembyteorder() const {
  // @@protoc_insertion_point(field_get:kvstore_ns.Transaction.systemByteOrder)
  return static_cast< ::kvstore_ns::ARCH_Info >(systembyteorder_);
}
inline void Transaction::set_systembyteorder(::kvstore_ns::ARCH_Info value) {
  
  systembyteorder_ = value;
  // @@protoc_insertion_point(field_set:kvstore_ns.Transaction.systemByteOrder)
}

// repeated .kvstore_ns.KeyValueSet keyValueSet = 5;
inline int Transaction::keyvalueset_size() const {
  return keyvalueset_.size();
}
inline void Transaction::clear_keyvalueset() {
  keyvalueset_.Clear();
}
inline const ::kvstore_ns::KeyValueSet& Transaction::keyvalueset(int index) const {
  // @@protoc_insertion_point(field_get:kvstore_ns.Transaction.keyValueSet)
  return keyvalueset_.Get(index);
}
inline ::kvstore_ns::KeyValueSet* Transaction::mutable_keyvalueset(int index) {
  // @@protoc_insertion_point(field_mutable:kvstore_ns.Transaction.keyValueSet)
  return keyvalueset_.Mutable(index);
}
inline ::kvstore_ns::KeyValueSet* Transaction::add_keyvalueset() {
  // @@protoc_insertion_point(field_add:kvstore_ns.Transaction.keyValueSet)
  return keyvalueset_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::kvstore_ns::KeyValueSet >*
Transaction::mutable_keyvalueset() {
  // @@protoc_insertion_point(field_mutable_list:kvstore_ns.Transaction.keyValueSet)
  return &keyvalueset_;
}
inline const ::google::protobuf::RepeatedPtrField< ::kvstore_ns::KeyValueSet >&
Transaction::keyvalueset() const {
  // @@protoc_insertion_point(field_list:kvstore_ns.Transaction.keyValueSet)
  return keyvalueset_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace kvstore_ns

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::kvstore_ns::DBASE_Action> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::kvstore_ns::DBASE_Action>() {
  return ::kvstore_ns::DBASE_Action_descriptor();
}
template <> struct is_proto_enum< ::kvstore_ns::TYPE_Info> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::kvstore_ns::TYPE_Info>() {
  return ::kvstore_ns::TYPE_Info_descriptor();
}
template <> struct is_proto_enum< ::kvstore_ns::ARCH_Info> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::kvstore_ns::ARCH_Info>() {
  return ::kvstore_ns::ARCH_Info_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_KVStore_2eproto__INCLUDED