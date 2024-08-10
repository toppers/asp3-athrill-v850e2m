FROM toppersjp/athrill-v850e2m-builder:v1.0.0 as asp3-athrill-v850e2m-builder

# rbenvとruby-buildをインストールし、Ruby 2.6.5をセットアップ
RUN git clone https://github.com/sstephenson/rbenv.git /root/.rbenv && \
    git clone https://github.com/sstephenson/ruby-build.git /root/.rbenv/plugins/ruby-build && \
    /root/.rbenv/bin/rbenv install 2.6.5 && \
    /root/.rbenv/bin/rbenv global 2.6.5

# Rubyのバージョンをパスに追加
ENV PATH /root/.rbenv/bin:/root/.rbenv/versions/2.6.5/bin:${PATH}

# RubyのエンコーディングをUTF-8に設定
ENV RUBYOPT -EUTF-8

WORKDIR /root/asp3