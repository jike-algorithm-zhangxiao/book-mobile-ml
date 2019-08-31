template <typename Dtype>
class ConvDorefaLayer : public Layer<Dtype> {
 public:
  explicit ConvDorefaLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "ConvDorefa"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top){}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom){}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

    shared_ptr<Layer<Dtype> > internalConv_layer_;
    bool containActive;  
    bool weightIntiByConv;
    int w_bit;
    int a_bit;
    int g_bit;
    int conv_learnable_blob_size;
    Blob<Dtype> bitW;
    Blob<Dtype> bitA;
    Blob<Dtype> bitG;
    Dtype scale_w;
    Dtype scale_a;
    Dtype quanK2Pow_w;
    Dtype quanK2Pow_a;
    Dtype quanK2Pow_g;
    bool blobsInitialized;
    void binaryFw(Blob<Dtype>*fp, Blob<Dtype>*bin,const Dtype&bitCount);
};