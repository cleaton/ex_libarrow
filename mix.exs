defmodule Mix.Tasks.Compile.ArrowNifs do
  def run(_args) do
    if match? {:win32, _}, :os.type do
      {result, _error_code} = System.cmd("nmake", ["/F", "Makefile.win", "priv\\markdown.dll"], stderr_to_stdout: true)
      IO.binwrite result
    else
      {result, _error_code} = System.cmd("make", ["ex_libarrow.so"], stderr_to_stdout: true)
      IO.binwrite result
    end
    :ok
  end
end

defmodule ExLibarrow.MixProject do
  use Mix.Project

  def project do
    [
      app: :ex_libarrow,
      version: "0.1.0",
      elixir: "~> 1.9",
      start_permanent: Mix.env() == :prod,
      deps: deps(),
      compilers: [:arrow_nifs] ++ Mix.compilers
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger]
    ]
  end


  # Run "mix help deps" to learn about dependencies.
  defp deps do
    arrow_build = """
    cd cpp && \
    cmake -DARROW_BUILD_UTILITIES=OFF -DARROW_PARQUET=ON -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/../../c_deps && \
    make -j #{:erlang.system_info(:logical_processors_available)} && make install
    """
    [
      {:libarrow, app: false, compile: arrow_build, git: "https://github.com/apache/arrow.git", tag: "apache-arrow-0.15.1"}
    ]
  end
end
