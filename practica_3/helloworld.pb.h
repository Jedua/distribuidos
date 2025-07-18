// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: helloworld.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_helloworld_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_helloworld_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019006 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_helloworld_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_helloworld_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_helloworld_2eproto;
namespace helloworld {
class Fecha;
struct FechaDefaultTypeInternal;
extern FechaDefaultTypeInternal _Fecha_default_instance_;
class HelloReply;
struct HelloReplyDefaultTypeInternal;
extern HelloReplyDefaultTypeInternal _HelloReply_default_instance_;
class HelloRequest;
struct HelloRequestDefaultTypeInternal;
extern HelloRequestDefaultTypeInternal _HelloRequest_default_instance_;
class SumaFechaRequest;
struct SumaFechaRequestDefaultTypeInternal;
extern SumaFechaRequestDefaultTypeInternal _SumaFechaRequest_default_instance_;
}  // namespace helloworld
PROTOBUF_NAMESPACE_OPEN
template<> ::helloworld::Fecha* Arena::CreateMaybeMessage<::helloworld::Fecha>(Arena*);
template<> ::helloworld::HelloReply* Arena::CreateMaybeMessage<::helloworld::HelloReply>(Arena*);
template<> ::helloworld::HelloRequest* Arena::CreateMaybeMessage<::helloworld::HelloRequest>(Arena*);
template<> ::helloworld::SumaFechaRequest* Arena::CreateMaybeMessage<::helloworld::SumaFechaRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace helloworld {

// ===================================================================

class HelloRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:helloworld.HelloRequest) */ {
 public:
  inline HelloRequest() : HelloRequest(nullptr) {}
  ~HelloRequest() override;
  explicit constexpr HelloRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  HelloRequest(const HelloRequest& from);
  HelloRequest(HelloRequest&& from) noexcept
    : HelloRequest() {
    *this = ::std::move(from);
  }

  inline HelloRequest& operator=(const HelloRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline HelloRequest& operator=(HelloRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HelloRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const HelloRequest* internal_default_instance() {
    return reinterpret_cast<const HelloRequest*>(
               &_HelloRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HelloRequest& a, HelloRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(HelloRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HelloRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HelloRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HelloRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const HelloRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const HelloRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HelloRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "helloworld.HelloRequest";
  }
  protected:
  explicit HelloRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // @@protoc_insertion_point(class_scope:helloworld.HelloRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_helloworld_2eproto;
};
// -------------------------------------------------------------------

class HelloReply final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:helloworld.HelloReply) */ {
 public:
  inline HelloReply() : HelloReply(nullptr) {}
  ~HelloReply() override;
  explicit constexpr HelloReply(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  HelloReply(const HelloReply& from);
  HelloReply(HelloReply&& from) noexcept
    : HelloReply() {
    *this = ::std::move(from);
  }

  inline HelloReply& operator=(const HelloReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline HelloReply& operator=(HelloReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HelloReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const HelloReply* internal_default_instance() {
    return reinterpret_cast<const HelloReply*>(
               &_HelloReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(HelloReply& a, HelloReply& b) {
    a.Swap(&b);
  }
  inline void Swap(HelloReply* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HelloReply* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HelloReply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HelloReply>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const HelloReply& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const HelloReply& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HelloReply* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "helloworld.HelloReply";
  }
  protected:
  explicit HelloReply(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 1,
  };
  // string message = 1;
  void clear_message();
  const std::string& message() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* message);
  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(const std::string& value);
  std::string* _internal_mutable_message();
  public:

  // @@protoc_insertion_point(class_scope:helloworld.HelloReply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_helloworld_2eproto;
};
// -------------------------------------------------------------------

class Fecha final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:helloworld.Fecha) */ {
 public:
  inline Fecha() : Fecha(nullptr) {}
  ~Fecha() override;
  explicit constexpr Fecha(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Fecha(const Fecha& from);
  Fecha(Fecha&& from) noexcept
    : Fecha() {
    *this = ::std::move(from);
  }

  inline Fecha& operator=(const Fecha& from) {
    CopyFrom(from);
    return *this;
  }
  inline Fecha& operator=(Fecha&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Fecha& default_instance() {
    return *internal_default_instance();
  }
  static inline const Fecha* internal_default_instance() {
    return reinterpret_cast<const Fecha*>(
               &_Fecha_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Fecha& a, Fecha& b) {
    a.Swap(&b);
  }
  inline void Swap(Fecha* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Fecha* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Fecha* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Fecha>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Fecha& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Fecha& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Fecha* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "helloworld.Fecha";
  }
  protected:
  explicit Fecha(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDiaFieldNumber = 1,
    kMesFieldNumber = 2,
    kAnioFieldNumber = 3,
  };
  // int32 dia = 1;
  void clear_dia();
  int32_t dia() const;
  void set_dia(int32_t value);
  private:
  int32_t _internal_dia() const;
  void _internal_set_dia(int32_t value);
  public:

  // int32 mes = 2;
  void clear_mes();
  int32_t mes() const;
  void set_mes(int32_t value);
  private:
  int32_t _internal_mes() const;
  void _internal_set_mes(int32_t value);
  public:

  // int32 anio = 3;
  void clear_anio();
  int32_t anio() const;
  void set_anio(int32_t value);
  private:
  int32_t _internal_anio() const;
  void _internal_set_anio(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:helloworld.Fecha)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int32_t dia_;
  int32_t mes_;
  int32_t anio_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_helloworld_2eproto;
};
// -------------------------------------------------------------------

class SumaFechaRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:helloworld.SumaFechaRequest) */ {
 public:
  inline SumaFechaRequest() : SumaFechaRequest(nullptr) {}
  ~SumaFechaRequest() override;
  explicit constexpr SumaFechaRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  SumaFechaRequest(const SumaFechaRequest& from);
  SumaFechaRequest(SumaFechaRequest&& from) noexcept
    : SumaFechaRequest() {
    *this = ::std::move(from);
  }

  inline SumaFechaRequest& operator=(const SumaFechaRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SumaFechaRequest& operator=(SumaFechaRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SumaFechaRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const SumaFechaRequest* internal_default_instance() {
    return reinterpret_cast<const SumaFechaRequest*>(
               &_SumaFechaRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(SumaFechaRequest& a, SumaFechaRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SumaFechaRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SumaFechaRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SumaFechaRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<SumaFechaRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const SumaFechaRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const SumaFechaRequest& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SumaFechaRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "helloworld.SumaFechaRequest";
  }
  protected:
  explicit SumaFechaRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFechaFieldNumber = 1,
    kDiasFieldNumber = 2,
  };
  // .helloworld.Fecha fecha = 1;
  bool has_fecha() const;
  private:
  bool _internal_has_fecha() const;
  public:
  void clear_fecha();
  const ::helloworld::Fecha& fecha() const;
  PROTOBUF_NODISCARD ::helloworld::Fecha* release_fecha();
  ::helloworld::Fecha* mutable_fecha();
  void set_allocated_fecha(::helloworld::Fecha* fecha);
  private:
  const ::helloworld::Fecha& _internal_fecha() const;
  ::helloworld::Fecha* _internal_mutable_fecha();
  public:
  void unsafe_arena_set_allocated_fecha(
      ::helloworld::Fecha* fecha);
  ::helloworld::Fecha* unsafe_arena_release_fecha();

  // int32 dias = 2;
  void clear_dias();
  int32_t dias() const;
  void set_dias(int32_t value);
  private:
  int32_t _internal_dias() const;
  void _internal_set_dias(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:helloworld.SumaFechaRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::helloworld::Fecha* fecha_;
  int32_t dias_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_helloworld_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HelloRequest

// string name = 1;
inline void HelloRequest::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& HelloRequest::name() const {
  // @@protoc_insertion_point(field_get:helloworld.HelloRequest.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void HelloRequest::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:helloworld.HelloRequest.name)
}
inline std::string* HelloRequest::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:helloworld.HelloRequest.name)
  return _s;
}
inline const std::string& HelloRequest::_internal_name() const {
  return name_.Get();
}
inline void HelloRequest::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* HelloRequest::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* HelloRequest::release_name() {
  // @@protoc_insertion_point(field_release:helloworld.HelloRequest.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void HelloRequest::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:helloworld.HelloRequest.name)
}

// -------------------------------------------------------------------

// HelloReply

// string message = 1;
inline void HelloReply::clear_message() {
  message_.ClearToEmpty();
}
inline const std::string& HelloReply::message() const {
  // @@protoc_insertion_point(field_get:helloworld.HelloReply.message)
  return _internal_message();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void HelloReply::set_message(ArgT0&& arg0, ArgT... args) {
 
 message_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:helloworld.HelloReply.message)
}
inline std::string* HelloReply::mutable_message() {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:helloworld.HelloReply.message)
  return _s;
}
inline const std::string& HelloReply::_internal_message() const {
  return message_.Get();
}
inline void HelloReply::_internal_set_message(const std::string& value) {
  
  message_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* HelloReply::_internal_mutable_message() {
  
  return message_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* HelloReply::release_message() {
  // @@protoc_insertion_point(field_release:helloworld.HelloReply.message)
  return message_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void HelloReply::set_allocated_message(std::string* message) {
  if (message != nullptr) {
    
  } else {
    
  }
  message_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), message,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (message_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    message_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:helloworld.HelloReply.message)
}

// -------------------------------------------------------------------

// Fecha

// int32 dia = 1;
inline void Fecha::clear_dia() {
  dia_ = 0;
}
inline int32_t Fecha::_internal_dia() const {
  return dia_;
}
inline int32_t Fecha::dia() const {
  // @@protoc_insertion_point(field_get:helloworld.Fecha.dia)
  return _internal_dia();
}
inline void Fecha::_internal_set_dia(int32_t value) {
  
  dia_ = value;
}
inline void Fecha::set_dia(int32_t value) {
  _internal_set_dia(value);
  // @@protoc_insertion_point(field_set:helloworld.Fecha.dia)
}

// int32 mes = 2;
inline void Fecha::clear_mes() {
  mes_ = 0;
}
inline int32_t Fecha::_internal_mes() const {
  return mes_;
}
inline int32_t Fecha::mes() const {
  // @@protoc_insertion_point(field_get:helloworld.Fecha.mes)
  return _internal_mes();
}
inline void Fecha::_internal_set_mes(int32_t value) {
  
  mes_ = value;
}
inline void Fecha::set_mes(int32_t value) {
  _internal_set_mes(value);
  // @@protoc_insertion_point(field_set:helloworld.Fecha.mes)
}

// int32 anio = 3;
inline void Fecha::clear_anio() {
  anio_ = 0;
}
inline int32_t Fecha::_internal_anio() const {
  return anio_;
}
inline int32_t Fecha::anio() const {
  // @@protoc_insertion_point(field_get:helloworld.Fecha.anio)
  return _internal_anio();
}
inline void Fecha::_internal_set_anio(int32_t value) {
  
  anio_ = value;
}
inline void Fecha::set_anio(int32_t value) {
  _internal_set_anio(value);
  // @@protoc_insertion_point(field_set:helloworld.Fecha.anio)
}

// -------------------------------------------------------------------

// SumaFechaRequest

// .helloworld.Fecha fecha = 1;
inline bool SumaFechaRequest::_internal_has_fecha() const {
  return this != internal_default_instance() && fecha_ != nullptr;
}
inline bool SumaFechaRequest::has_fecha() const {
  return _internal_has_fecha();
}
inline void SumaFechaRequest::clear_fecha() {
  if (GetArenaForAllocation() == nullptr && fecha_ != nullptr) {
    delete fecha_;
  }
  fecha_ = nullptr;
}
inline const ::helloworld::Fecha& SumaFechaRequest::_internal_fecha() const {
  const ::helloworld::Fecha* p = fecha_;
  return p != nullptr ? *p : reinterpret_cast<const ::helloworld::Fecha&>(
      ::helloworld::_Fecha_default_instance_);
}
inline const ::helloworld::Fecha& SumaFechaRequest::fecha() const {
  // @@protoc_insertion_point(field_get:helloworld.SumaFechaRequest.fecha)
  return _internal_fecha();
}
inline void SumaFechaRequest::unsafe_arena_set_allocated_fecha(
    ::helloworld::Fecha* fecha) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(fecha_);
  }
  fecha_ = fecha;
  if (fecha) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:helloworld.SumaFechaRequest.fecha)
}
inline ::helloworld::Fecha* SumaFechaRequest::release_fecha() {
  
  ::helloworld::Fecha* temp = fecha_;
  fecha_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::helloworld::Fecha* SumaFechaRequest::unsafe_arena_release_fecha() {
  // @@protoc_insertion_point(field_release:helloworld.SumaFechaRequest.fecha)
  
  ::helloworld::Fecha* temp = fecha_;
  fecha_ = nullptr;
  return temp;
}
inline ::helloworld::Fecha* SumaFechaRequest::_internal_mutable_fecha() {
  
  if (fecha_ == nullptr) {
    auto* p = CreateMaybeMessage<::helloworld::Fecha>(GetArenaForAllocation());
    fecha_ = p;
  }
  return fecha_;
}
inline ::helloworld::Fecha* SumaFechaRequest::mutable_fecha() {
  ::helloworld::Fecha* _msg = _internal_mutable_fecha();
  // @@protoc_insertion_point(field_mutable:helloworld.SumaFechaRequest.fecha)
  return _msg;
}
inline void SumaFechaRequest::set_allocated_fecha(::helloworld::Fecha* fecha) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete fecha_;
  }
  if (fecha) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::helloworld::Fecha>::GetOwningArena(fecha);
    if (message_arena != submessage_arena) {
      fecha = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, fecha, submessage_arena);
    }
    
  } else {
    
  }
  fecha_ = fecha;
  // @@protoc_insertion_point(field_set_allocated:helloworld.SumaFechaRequest.fecha)
}

// int32 dias = 2;
inline void SumaFechaRequest::clear_dias() {
  dias_ = 0;
}
inline int32_t SumaFechaRequest::_internal_dias() const {
  return dias_;
}
inline int32_t SumaFechaRequest::dias() const {
  // @@protoc_insertion_point(field_get:helloworld.SumaFechaRequest.dias)
  return _internal_dias();
}
inline void SumaFechaRequest::_internal_set_dias(int32_t value) {
  
  dias_ = value;
}
inline void SumaFechaRequest::set_dias(int32_t value) {
  _internal_set_dias(value);
  // @@protoc_insertion_point(field_set:helloworld.SumaFechaRequest.dias)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace helloworld

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_helloworld_2eproto
