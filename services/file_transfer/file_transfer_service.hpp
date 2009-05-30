#ifndef FILE_TRANSFER_SERVICE_HPP_
#define FILE_TRANSFER_SERVICE_HPP_
#include "base/base.hpp"
#include "base/hash.hpp"
#include "thread/threadpool.hpp"
#include <boost/thread/mutex.hpp>
#include "server/protobuf_connection.hpp"
#include "services/file_transfer/checkbook.hpp"
#include "services/file_transfer/file_transfer.pb.h"
class FileTransferClient;
class TransferInfo;
class Connection;
class FileTransferServiceImpl : public FileTransfer::FileTransferService {
 public:
  FileTransferServiceImpl(const string &doc_root) : doc_root_(doc_root), threadpool_("FileTransferServiceImplDownloadThreadPool", 2) {
  }
  void ReceiveCheckBook(google::protobuf::RpcController *controller,
                        const FileTransfer::CheckBook *request,
                        FileTransfer::CheckBookResponse *response,
                        google::protobuf::Closure *done);
  void ReceiveSlice(google::protobuf::RpcController *controller,
                    const FileTransfer::SliceRequest *request,
                    FileTransfer::SliceResponse *response,
                    google::protobuf::Closure *done);
  void Register(google::protobuf::RpcController *controller,
                const FileTransfer::RegisterRequest *request,
                FileTransfer::RegisterResponse *response,
                google::protobuf::Closure *done);
 private:
  void CloseChannel(FullDualChannel *channel);
  boost::shared_ptr<TransferInfo> GetTransferInfoFromConnection(
    const Connection *connection,
    const string &checkbook_dest_filename) const;
  boost::shared_ptr<TransferInfo> GetTransferInfoFromDestName(
    const string &checkbook_dest_filename);
  boost::shared_ptr<TransferInfo> LoadTransferInfoFromDisk(
    const string &checkbook_dest_filename);
  boost::shared_ptr<TransferInfo> GetTransferInfo(
    Connection *connection,
    const string &checkbook_dest_filename);
  bool SaveSliceRequest(const FileTransfer::SliceRequest *slice_request);
  void CloseConnection(const Connection *connection);
  boost::mutex table_mutex_;
  typedef hash_map<string, boost::shared_ptr<TransferInfo> > CheckBookTable;
  typedef hash_map<const Connection*, CheckBookTable> ConnectionToCheckBookTable;
  typedef hash_map<FullDualChannel*, hash_set<string> > ChannelTable;
  typedef hash_map<string, pair<int, boost::shared_ptr<FileTransferClient> > >
    TransferClientTable;
  ConnectionToCheckBookTable connection_table_;
  CheckBookTable check_table_;
  TransferClientTable transfer_client_table_;
  boost::mutex transfer_client_table_mutex_;
  ChannelTable channel_table_;
  string doc_root_;
  ThreadPool threadpool_;
};
#endif  // FILE_TRANSFER_SERVICE_HPP_